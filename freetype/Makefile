#
# Copyright (C) 2021 Xiaomi Corporation
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

TOP_DIR = freetype
MODULES_CFG = $(TOP_DIR)/builds/nuttx/modules.cfg
FTOPTION_H = $(TOP_DIR)/builds/nuttx/ftoption.h
CONFIG_MK = $(TOP_DIR)/builds/nuttx/nuttx.mk

include $(TOP_DIR)/Makefile

context:: copy_submodule

register::

depend::
	$(Q) touch .depend

distclean:
	$(call DELFILE, .depend)

install::
