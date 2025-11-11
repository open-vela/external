#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <libcamera/libcamera.h>

using namespace libcamera;
using namespace std;

extern "C" void reference_vela_pipeline_handler();

std::shared_ptr<libcamera::Camera> camera;
int completeBuffersCount = 0;
int completeRequestsCount = 0;

void bufferComplete(Request *request, FrameBuffer *buffer) {
    std::cout << "Get FrameBuffer index:" << completeBuffersCount << std::endl;
    if (buffer->metadata().status != FrameMetadata::FrameSuccess)
      return;

    completeBuffersCount++;
}

void requestComplete(Request *request) {
    std::cout << "Get completeRequestsCount index:" << completeRequestsCount
              << " request status: " << request->status() << std::endl;
    if (request->status() != Request::RequestComplete)
      return;

    completeRequestsCount++;

    request->reuse(Request::ReuseBuffers);
    camera->queueRequest(request);
}

extern "C" int main(void) {
    int ret;
    std::cout << "libcamera demo application" << std::endl;
    reference_vela_pipeline_handler();

    // 1. Create camera manager and start it.
    CameraManager *cm;

    cm = new CameraManager();
    if (!cm) {
        std::cerr << "Failed to new camera manager" << endl;
        return EXIT_FAILURE;
    }

    if (cm->start()) {
        std::cerr << "Failed to start camera manager" << endl;
        return EXIT_FAILURE;
    }

    camera = cm->get("0");
    if (!camera) {
        std::cerr << "Can not find '" << "video" << "' camera" << endl;
        return EXIT_FAILURE;
    }

    if (camera->acquire()) {
        std::cerr << "Can not acquire '" << "video" << "' camera" << endl;
        return EXIT_FAILURE;
    }

    if (camera->streams().empty()) {
        std::cerr << "Camera has no stream" << endl;
        return EXIT_FAILURE;
    }

    std::cout << "Using camera: " << camera->id() << std::endl;

    // 2. Configure camera.
    std::unique_ptr<CameraConfiguration> config;

    config = camera->generateConfiguration({ StreamRole::VideoRecording });
    if (!config) {
        std::cerr << "Failed to generate camera configuration" << std::endl;
        return EXIT_FAILURE;
    }

    StreamConfiguration &streamConfig = config->at(0);
    std::cout << "Default configuration: " << streamConfig.toString() << std::endl;

    streamConfig.size.width = 640;
    streamConfig.size.height = 480;
    streamConfig.pixelFormat = formats::YUV420;
    streamConfig.bufferCount = 2;

    if (camera->configure(config.get()) < 0) {
        std::cerr << "Failed to configure camera" << std::endl;
        return EXIT_FAILURE;
    }

    // 3. Create requests and allocate buffers.
    FrameBufferAllocator *allocator;
    std::vector<std::unique_ptr<Request>> requests;
    allocator = new FrameBufferAllocator(camera);

    Stream *stream = streamConfig.stream();
    ret = allocator->allocate(stream);
    if (ret < 0) {
        std::cerr << "Failed to allocate stream" << std::endl;
        return EXIT_FAILURE;
    }

    for (const std::unique_ptr<FrameBuffer> &buffer : allocator->buffers(stream)) {
      std::unique_ptr<Request> request = camera->createRequest();
      if (!request) {
        std::cerr << "Failed to createRequest" << std::endl;
        return EXIT_FAILURE;
      }

      if (request->addBuffer(stream, buffer.get())) {
        std::cerr << "Failed to addBuffer" << std::endl;
        return EXIT_FAILURE;
      }

      requests.push_back(std::move(request));
    }

    camera->bufferCompleted.connect(bufferComplete);
    camera->requestCompleted.connect(requestComplete);

    // 4. Start camera.
    if (camera->start()) {
        std::cerr << "Failed to start camera" << std::endl;
        return EXIT_FAILURE;
    }

    for (std::unique_ptr<Request> &request : requests) {
        if (camera->queueRequest(request.get()) < 0) {
            std::cerr << "Failed to queue request" << std::endl;
            return EXIT_FAILURE;
        }
    }

    while (completeBuffersCount < 100) {
        sleep(1);
    }

    // 5. Exit
    std::cout << "Read frame done " << completeBuffersCount << " exit!" << std::endl;

    camera->stop();
    camera->release();
    cm->stop();
    delete cm;
    delete allocator;
    return EXIT_SUCCESS;
}