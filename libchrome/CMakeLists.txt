#
# Copyright (C) 2021 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License"); you may not
# use this file except in compliance with the License. You may obtain a copy of
# the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations under
# the License.
#
if(CONFIG_LIB_CHROMIUM)

  nuttx_add_library(libchrome STATIC)

  set(CXXSRCS
      libchrome/base/at_exit.cc
      libchrome/base/base64.cc
      libchrome/base/base_switches.cc
      libchrome/base/build_time.cc
      libchrome/base/callback_helpers.cc
      libchrome/base/callback_internal.cc
      libchrome/base/command_line.cc
      libchrome/base/cpu.cc
      libchrome/base/debug/activity_tracker.cc
      libchrome/base/debug/alias.cc
      libchrome/base/debug/debugger.cc
      libchrome/base/debug/debugger_posix.cc
      libchrome/base/debug/dump_without_crashing.cc
      libchrome/base/debug/stack_trace.cc
      libchrome/base/debug/task_annotator.cc
      libchrome/base/environment.cc
      libchrome/base/feature_list.cc
      libchrome/base/files/file.cc
      libchrome/base/files/file_descriptor_watcher_posix.cc
      libchrome/base/files/file_enumerator.cc
      libchrome/base/files/file_enumerator_posix.cc
      libchrome/base/files/file_path.cc
      libchrome/base/files/file_path_constants.cc
      libchrome/base/files/file_path_watcher.cc
      libchrome/base/files/file_posix.cc
      libchrome/base/files/file_tracing.cc
      libchrome/base/files/file_util.cc
      libchrome/base/files/file_util_posix.cc
      libchrome/base/files/important_file_writer.cc
      libchrome/base/files/memory_mapped_file.cc
      libchrome/base/files/memory_mapped_file_posix.cc
      libchrome/base/files/scoped_file.cc
      libchrome/base/files/scoped_temp_dir.cc
      libchrome/base/guid.cc
      libchrome/base/json/json_parser.cc
      libchrome/base/json/json_reader.cc
      libchrome/base/json/json_string_value_serializer.cc
      libchrome/base/json/json_writer.cc
      libchrome/base/json/string_escape.cc
      libchrome/base/lazy_instance_helpers.cc
      libchrome/base/location.cc
      libchrome/base/logging.cc
      libchrome/base/md5.cc
      libchrome/base/memory/ref_counted.cc
      libchrome/base/memory/ref_counted_memory.cc
      libchrome/base/memory/shared_memory_handle.cc
      libchrome/base/memory/shared_memory_handle_posix.cc
      libchrome/base/memory/weak_ptr.cc
      libchrome/base/message_loop/incoming_task_queue.cc
      libchrome/base/message_loop/message_loop.cc
      libchrome/base/message_loop/message_loop_current.cc
      libchrome/base/message_loop/message_loop_task_runner.cc
      libchrome/base/message_loop/message_pump.cc
      libchrome/base/message_loop/message_pump_default.cc
      libchrome/base/message_loop/watchable_io_message_pump_posix.cc
      libchrome/base/metrics/bucket_ranges.cc
      libchrome/base/metrics/dummy_histogram.cc
      libchrome/base/metrics/field_trial.cc
      libchrome/base/metrics/field_trial_param_associator.cc
      libchrome/base/metrics/histogram_base.cc
      libchrome/base/metrics/histogram.cc
      libchrome/base/metrics/histogram_functions.cc
      libchrome/base/metrics/histogram_samples.cc
      libchrome/base/metrics/histogram_snapshot_manager.cc
      libchrome/base/metrics/metrics_hashes.cc
      libchrome/base/metrics/persistent_histogram_allocator.cc
      libchrome/base/metrics/persistent_memory_allocator.cc
      libchrome/base/metrics/persistent_sample_map.cc
      libchrome/base/metrics/sample_map.cc
      libchrome/base/metrics/sample_vector.cc
      libchrome/base/metrics/sparse_histogram.cc
      libchrome/base/metrics/statistics_recorder.cc
      libchrome/base/native_library.cc
      libchrome/base/observer_list_threadsafe.cc
      libchrome/base/path_service.cc
      libchrome/base/pending_task.cc
      libchrome/base/pickle.cc
      libchrome/base/posix/file_descriptor_shuffle.cc
      libchrome/base/posix/global_descriptors.cc
      libchrome/base/posix/safe_strerror.cc
      libchrome/base/process/internal_linux.cc
      libchrome/base/process/kill.cc
      libchrome/base/process/launch.cc
      libchrome/base/process/memory_stubs.cc
      libchrome/base/process/process_handle.cc
      libchrome/base/process/process_handle_linux.cc
      libchrome/base/process/process_handle_posix.cc
      libchrome/base/process/process_info_linux.cc
      libchrome/base/process/process_iterator.cc
      libchrome/base/process/process_iterator_linux.cc
      libchrome/base/process/process_metrics.cc
      libchrome/base/process/process_posix.cc
      libchrome/base/rand_util.cc
      libchrome/base/rand_util_posix.cc
      libchrome/base/run_loop.cc
      libchrome/base/sequence_checker_impl.cc
      libchrome/base/sequenced_task_runner.cc
      libchrome/base/sequence_token.cc
      libchrome/base/sha1.cc
      libchrome/base/strings/pattern.cc
      libchrome/base/strings/safe_sprintf.cc
      libchrome/base/strings/string16.cc
      libchrome/base/strings/string_number_conversions.cc
      libchrome/base/strings/string_piece.cc
      libchrome/base/strings/stringprintf.cc
      libchrome/base/strings/string_split.cc
      libchrome/base/strings/string_util.cc
      libchrome/base/strings/string_util_constants.cc
      libchrome/base/strings/sys_string_conversions_posix.cc
      libchrome/base/strings/utf_string_conversions.cc
      libchrome/base/strings/utf_string_conversion_utils.cc
      libchrome/base/synchronization/atomic_flag.cc
      libchrome/base/synchronization/condition_variable_posix.cc
      libchrome/base/synchronization/lock.cc
      libchrome/base/synchronization/lock_impl_posix.cc
      libchrome/base/synchronization/waitable_event_posix.cc
      libchrome/base/sys_info.cc
      libchrome/base/sys_info_linux.cc
      libchrome/base/task/cancelable_task_tracker.cc
      libchrome/base/task_runner.cc
      libchrome/base/third_party/icu/icu_utf.cc
      libchrome/base/third_party/nspr/prtime.cc
      libchrome/base/threading/platform_thread_internal_posix.cc
      libchrome/base/threading/platform_thread_linux.cc
      libchrome/base/threading/platform_thread_posix.cc
      libchrome/base/threading/post_task_and_reply_impl.cc
      libchrome/base/threading/scoped_blocking_call.cc
      libchrome/base/threading/sequenced_task_runner_handle.cc
      libchrome/base/threading/sequence_local_storage_map.cc
      libchrome/base/threading/sequence_local_storage_slot.cc
      libchrome/base/threading/simple_thread.cc
      libchrome/base/threading/thread.cc
      libchrome/base/threading/thread_checker_impl.cc
      libchrome/base/threading/thread_collision_warner.cc
      libchrome/base/threading/thread_id_name_manager.cc
      libchrome/base/threading/thread_local_storage.cc
      libchrome/base/threading/thread_local_storage_posix.cc
      libchrome/base/threading/thread_restrictions.cc
      libchrome/base/threading/thread_task_runner_handle.cc
      libchrome/base/time/clock.cc
      libchrome/base/time/default_clock.cc
      libchrome/base/time/default_tick_clock.cc
      libchrome/base/timer/elapsed_timer.cc
      libchrome/base/timer/timer.cc
      libchrome/base/time/tick_clock.cc
      libchrome/base/time/time.cc
      libchrome/base/time/time_conversion_posix.cc
      libchrome/base/time/time_exploded_posix.cc
      libchrome/base/time/time_now_posix.cc
      libchrome/base/time/time_override.cc
      libchrome/base/unguessable_token.cc
      libchrome/base/value_iterators.cc
      libchrome/base/values.cc
      libchrome/base/version.cc
      libchrome/base/vlog.cc
      libchrome/nuttx/base/debug/stack_trace_posix.cc
      libchrome/nuttx/base/memory/shared_memory_posix.cc
      libchrome/nuttx/base/message_loop/message_pump_glib.cc
      libchrome/nuttx/base/message_loop/message_pump_libevent.cc
      libchrome/nuttx/base/sys_info_posix.cc
      modp_b64/modp_b64.cc)

  set(CXXFLAGS
      -DOS_POSIX
      -D_POSIX_MONOTONIC_CLOCK=1
      -Wno-undef
      -Wno-shadow
      -Wno-unused-variable
      -Wno-unused-but-set-variable
      -Wno-unused-value
      -Wno-sign-compare
      -D_GNU_SOURCE
      -fpermissive
      -fno-exceptions
      -U__GLIBCXX__)

  set(INCDIR
      ${CMAKE_CURRENT_LIST_DIR}/libchrome/nuttx
      ${CMAKE_CURRENT_LIST_DIR}/libchrome ${CMAKE_CURRENT_LIST_DIR}/modp_b64
      ${CMAKE_CURRENT_LIST_DIR}/modp_b64/modp_b64)

  target_sources(libchrome PRIVATE ${CXXSRCS})
  target_compile_options(libchrome PRIVATE ${CXXFLAGS})
  target_include_directories(libchrome PRIVATE ${INCDIR})
endif()
