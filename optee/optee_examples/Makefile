
#
# Copyright (C) 2023 Xiaomi Corporation
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

ifneq ($(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD),)
CFLAGS += ${INCDIR_PREFIX}optee_examples/hello_world/ta/include
PROGNAME += $(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_PROGNAME)
PRIORITY += $(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_PRIORITY)
STACKSIZE += $(CONFIG_OPTEE_EXAMPLES_CA_HELLOWORLD_STACKSIZE)
MAINSRC += optee_examples/hello_world/host/main.c
endif

ifneq ($(CONFIG_OPTEE_EXAMPLES_TA_HELLOWORLD),)
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutee/include
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/external/optee/optee_os/optee_os/lib/libutils/ext/include
CFLAGS += ${INCDIR_PREFIX}optee_examples/hello_world/ta/include
CFLAGS += -DHELLO_WORLD_TA_NAME=\"hello_world.ta\"
CSRCS += hello_world_ta.c
VPATH = :optee_examples/hello_world/ta
endif

include $(APPDIR)/Application.mk
