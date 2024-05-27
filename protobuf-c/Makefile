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

#
# protobuf-c
#
CSRCS = $(wildcard protobuf-c/protobuf-c/*.c)

ifeq ($(CONFIG_PROTOBUF_C_TEST),y)
context::
	$(Q) cd protobuf-c && \
	protoc-c --c_out=. t/test.proto && \
	protoc-c --c_out=. t/test-full.proto && \
	protoc-c --c_out=. t/test-optimized.proto
	$(Q) cd protobuf-c/protobuf-c && \
	protoc-c --c_out=. protobuf-c.proto
	$(Q) protoc-c --c_out=. google/protobuf/descriptor.proto

clean::
	$(call DELFILE, protobuf-c/t/*pb-c.h)
	$(call DELFILE, protobuf-c/t/*pb-c.c)
	$(call DELFILE, protobuf-c/protobuf-c/*pb-c.h)
	$(call DELFILE, protobuf-c/protobuf-c/*pb-c.c)
	$(call DELFILE, google/protobuf/descriptor.pb-c.*)

CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/protobuf-c/protobuf-c
CFLAGS   += ${INCDIR_PREFIX}$(APPDIR)/external/protobuf-c
CSRCS    += $(wildcard protobuf-c/t/*.c)
PRIORITY  = $(CONFIG_PROTOBUF_C_TEST_PRIORITY)
STACKSIZE = $(CONFIG_PROTOBUF_C_TEST_STACKSIZE)
MAINSRC  += protobuf-c/t/generated-code/test-generated-code.c
PROGNAME += test_generated_code
endif

include $(APPDIR)/Application.mk
