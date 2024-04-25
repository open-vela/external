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

CSRCS  = pcre2/src/pcre2_dftables.c pcre2/src/pcre2_auto_possess.c
CSRCS += pcre2_chartables.c pcre2/src/pcre2_chkdint.c pcre2/src/pcre2_compile.c
CSRCS += pcre2/src/pcre2_config.c pcre2/src/pcre2_context.c pcre2/src/pcre2_convert.c
CSRCS += pcre2/src/pcre2_dfa_match.c pcre2/src/pcre2_error.c pcre2/src/pcre2_extuni.c
CSRCS += pcre2/src/pcre2_find_bracket.c pcre2/src/pcre2_jit_compile.c
CSRCS += pcre2/src/pcre2_maketables.c pcre2/src/pcre2_match.c pcre2/src/pcre2_match_data.c
CSRCS += pcre2/src/pcre2_newline.c pcre2/src/pcre2_ord2utf.c pcre2/src/pcre2_pattern_info.c
CSRCS += pcre2/src/pcre2_script_run.c pcre2/src/pcre2_serialize.c
CSRCS += pcre2/src/pcre2_string_utils.c pcre2/src/pcre2_study.c pcre2/src/pcre2_substitute.c
CSRCS += pcre2/src/pcre2_substring.c pcre2/src/pcre2_tables.c pcre2/src/pcre2_ucd.c
CSRCS += pcre2/src/pcre2_valid_utf.c pcre2/src/pcre2_xclass.c

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}pcre2/src
CFLAGS += -DPCRE2_CODE_UNIT_WIDTH=8 -DHAVE_CONFIG_H

include $(APPDIR)/Application.mk
