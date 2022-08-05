#
# Copyright (C) 2020 Xiaomi Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include $(APPDIR)/Make.defs

CXXEXT = .cc

CXXSRCS += base/at_exit.cc
CXXSRCS += base/base64.cc
CXXSRCS += base/base_switches.cc
CXXSRCS += base/build_time.cc
CXXSRCS += base/callback_helpers.cc
CXXSRCS += base/callback_internal.cc
CXXSRCS += base/command_line.cc
CXXSRCS += base/cpu.cc
CXXSRCS += base/debug/activity_tracker.cc
CXXSRCS += base/debug/alias.cc
CXXSRCS += base/debug/debugger.cc
CXXSRCS += base/debug/debugger_posix.cc
CXXSRCS += base/debug/dump_without_crashing.cc
CXXSRCS += base/debug/stack_trace.cc
CXXSRCS += base/debug/task_annotator.cc
CXXSRCS += base/environment.cc
CXXSRCS += base/feature_list.cc
CXXSRCS += base/files/file.cc
CXXSRCS += base/files/file_descriptor_watcher_posix.cc
CXXSRCS += base/files/file_enumerator.cc
CXXSRCS += base/files/file_enumerator_posix.cc
CXXSRCS += base/files/file_path.cc
CXXSRCS += base/files/file_path_constants.cc
CXXSRCS += base/files/file_path_watcher.cc
CXXSRCS += base/files/file_posix.cc
CXXSRCS += base/files/file_tracing.cc
CXXSRCS += base/files/file_util.cc
CXXSRCS += base/files/file_util_posix.cc
CXXSRCS += base/files/important_file_writer.cc
CXXSRCS += base/files/memory_mapped_file.cc
CXXSRCS += base/files/memory_mapped_file_posix.cc
CXXSRCS += base/files/scoped_file.cc
CXXSRCS += base/files/scoped_temp_dir.cc
CXXSRCS += base/guid.cc
CXXSRCS += base/json/json_parser.cc
CXXSRCS += base/json/json_reader.cc
CXXSRCS += base/json/json_string_value_serializer.cc
CXXSRCS += base/json/json_writer.cc
CXXSRCS += base/json/string_escape.cc
CXXSRCS += base/lazy_instance_helpers.cc
CXXSRCS += base/location.cc
CXXSRCS += base/logging.cc
CXXSRCS += base/md5.cc
CXXSRCS += base/memory/ref_counted.cc
CXXSRCS += base/memory/ref_counted_memory.cc
CXXSRCS += base/memory/shared_memory_handle.cc
CXXSRCS += base/memory/shared_memory_handle_posix.cc
CXXSRCS += base/memory/weak_ptr.cc
CXXSRCS += base/message_loop/incoming_task_queue.cc
CXXSRCS += base/message_loop/message_loop.cc
CXXSRCS += base/message_loop/message_loop_current.cc
CXXSRCS += base/message_loop/message_loop_task_runner.cc
CXXSRCS += base/message_loop/message_pump.cc
CXXSRCS += base/message_loop/message_pump_default.cc
CXXSRCS += base/message_loop/watchable_io_message_pump_posix.cc
CXXSRCS += base/metrics/bucket_ranges.cc
CXXSRCS += base/metrics/dummy_histogram.cc
CXXSRCS += base/metrics/field_trial.cc
CXXSRCS += base/metrics/field_trial_param_associator.cc
CXXSRCS += base/metrics/histogram_base.cc
CXXSRCS += base/metrics/histogram.cc
CXXSRCS += base/metrics/histogram_functions.cc
CXXSRCS += base/metrics/histogram_samples.cc
CXXSRCS += base/metrics/histogram_snapshot_manager.cc
CXXSRCS += base/metrics/metrics_hashes.cc
CXXSRCS += base/metrics/persistent_histogram_allocator.cc
CXXSRCS += base/metrics/persistent_memory_allocator.cc
CXXSRCS += base/metrics/persistent_sample_map.cc
CXXSRCS += base/metrics/sample_map.cc
CXXSRCS += base/metrics/sample_vector.cc
CXXSRCS += base/metrics/sparse_histogram.cc
CXXSRCS += base/metrics/statistics_recorder.cc
CXXSRCS += base/native_library.cc
CXXSRCS += base/observer_list_threadsafe.cc
CXXSRCS += base/path_service.cc
CXXSRCS += base/pending_task.cc
CXXSRCS += base/pickle.cc
CXXSRCS += base/posix/file_descriptor_shuffle.cc
CXXSRCS += base/posix/global_descriptors.cc
CXXSRCS += base/posix/safe_strerror.cc
CXXSRCS += base/process/internal_linux.cc
CXXSRCS += base/process/kill.cc
CXXSRCS += base/process/launch.cc
CXXSRCS += base/process/memory_stubs.cc
CXXSRCS += base/process/process_handle.cc
CXXSRCS += base/process/process_handle_linux.cc
CXXSRCS += base/process/process_handle_posix.cc
CXXSRCS += base/process/process_info_linux.cc
CXXSRCS += base/process/process_iterator.cc
CXXSRCS += base/process/process_iterator_linux.cc
CXXSRCS += base/process/process_metrics.cc
CXXSRCS += base/process/process_posix.cc
CXXSRCS += base/rand_util.cc
CXXSRCS += base/rand_util_posix.cc
CXXSRCS += base/run_loop.cc
CXXSRCS += base/sequence_checker_impl.cc
CXXSRCS += base/sequenced_task_runner.cc
CXXSRCS += base/sequence_token.cc
CXXSRCS += base/sha1.cc
CXXSRCS += base/strings/pattern.cc
CXXSRCS += base/strings/safe_sprintf.cc
CXXSRCS += base/strings/string16.cc
CXXSRCS += base/strings/string_number_conversions.cc
CXXSRCS += base/strings/string_piece.cc
CXXSRCS += base/strings/stringprintf.cc
CXXSRCS += base/strings/string_split.cc
CXXSRCS += base/strings/string_util.cc
CXXSRCS += base/strings/string_util_constants.cc
CXXSRCS += base/strings/sys_string_conversions_posix.cc
CXXSRCS += base/strings/utf_string_conversions.cc
CXXSRCS += base/strings/utf_string_conversion_utils.cc
CXXSRCS += base/synchronization/atomic_flag.cc
CXXSRCS += base/synchronization/condition_variable_posix.cc
CXXSRCS += base/synchronization/lock.cc
CXXSRCS += base/synchronization/lock_impl_posix.cc
CXXSRCS += base/synchronization/waitable_event_posix.cc
CXXSRCS += base/sys_info.cc
CXXSRCS += base/sys_info_linux.cc
CXXSRCS += base/task/cancelable_task_tracker.cc
CXXSRCS += base/task_runner.cc
CXXSRCS += base/third_party/icu/icu_utf.cc
CXXSRCS += base/third_party/nspr/prtime.cc
CXXSRCS += base/threading/platform_thread_internal_posix.cc
CXXSRCS += base/threading/platform_thread_linux.cc
CXXSRCS += base/threading/platform_thread_posix.cc
CXXSRCS += base/threading/post_task_and_reply_impl.cc
CXXSRCS += base/threading/scoped_blocking_call.cc
CXXSRCS += base/threading/sequenced_task_runner_handle.cc
CXXSRCS += base/threading/sequence_local_storage_map.cc
CXXSRCS += base/threading/sequence_local_storage_slot.cc
CXXSRCS += base/threading/simple_thread.cc
CXXSRCS += base/threading/thread.cc
CXXSRCS += base/threading/thread_checker_impl.cc
CXXSRCS += base/threading/thread_collision_warner.cc
CXXSRCS += base/threading/thread_id_name_manager.cc
CXXSRCS += base/threading/thread_local_storage.cc
CXXSRCS += base/threading/thread_local_storage_posix.cc
CXXSRCS += base/threading/thread_restrictions.cc
CXXSRCS += base/threading/thread_task_runner_handle.cc
CXXSRCS += base/time/clock.cc
CXXSRCS += base/time/default_clock.cc
CXXSRCS += base/time/default_tick_clock.cc
CXXSRCS += base/timer/elapsed_timer.cc
CXXSRCS += base/timer/timer.cc
CXXSRCS += base/time/tick_clock.cc
CXXSRCS += base/time/time.cc
CXXSRCS += base/time/time_conversion_posix.cc
CXXSRCS += base/time/time_exploded_posix.cc
CXXSRCS += base/time/time_now_posix.cc
CXXSRCS += base/time/time_override.cc
CXXSRCS += base/unguessable_token.cc
CXXSRCS += base/value_iterators.cc
CXXSRCS += base/values.cc
CXXSRCS += base/version.cc
CXXSRCS += base/vlog.cc
CXXSRCS += nuttx/base/debug/stack_trace_posix.cc
CXXSRCS += nuttx/base/memory/shared_memory_posix.cc
CXXSRCS += nuttx/base/message_loop/message_pump_glib.cc
CXXSRCS += nuttx/base/message_loop/message_pump_libevent.cc
CXXSRCS += nuttx/base/sys_info_posix.cc

CXXFLAGS += -DOS_POSIX -D_POSIX_MONOTONIC_CLOCK=1 -DNDEBUG
CXXFLAGS += -Wno-undef -Wno-shadow -Wno-unused-variable -Wno-unused-but-set-variable -Wno-unused-value -Wno-sign-compare
CXXFLAGS += -D_GNU_SOURCE -fpermissive -fno-exceptions
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" nuttx}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CXXFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/modp_b64/modp_b64}

include $(APPDIR)/Application.mk
