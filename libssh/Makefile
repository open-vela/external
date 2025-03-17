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

CFLAGS += ${INCDIR_PREFIX}.
CFLAGS += ${INCDIR_PREFIX}$(APPDIR)/system/zlib/zlib

CFLAGS += -DTHREAD_STACKSIZE=CONFIG_UTILS_SSH_STACKSIZE
CFLAGS += -DBLOCKSIZE=4096 -DBUF_SIZE=4096 -DCHUNKSIZE=4096
CFLAGS += -DERROR_BUFFERLEN=512 -DLOG_SIZE=256 -DMAX_LINE_SIZE=512
CFLAGS += -Dmd5_init=sshmd5_init -Dmd5_update=sshmd5_update -Dmd5_final=sshmd5_final
CFLAGS += -Dsha1_init=sshsha1_init -Dsha256_init=sshsha256_init
CFLAGS += -Dsha384_init=sshsha384_init -Dsha512_init=sshsha512_init
CFLAGS += -Dhmac_init=ssh_hmac_init
CFLAGS += -Wno-deprecated-declarations

SKIP  = libssh/src/dh_crypto.c libssh/src/ecdh_crypto.c libssh/src/ecdh_gcrypt.c
SKIP += libssh/src/gcrypt_missing.c libssh/src/getrandom_crypto.c
SKIP += libssh/src/getrandom_gcrypt.c libssh/src/gssapi.c libssh/src/libcrypto.c
SKIP += libssh/src/libcrypto-compat.c libssh/src/libgcrypt.c libssh/src/md_crypto.c
SKIP += libssh/src/md_gcrypt.c libssh/src/pki_crypto.c libssh/src/pki_gcrypt.c
SKIP += libssh/src/threads/libcrypto.c libssh/src/threads/libgcrypt.c libssh/src/threads/winlocks.c
ifneq ($(CONFIG_TEST_SSH),)
SKIP += libssh/src/buffer.c libssh/src/socket.c libssh/src/packet.c libssh/src/error.c
SKIP += libssh/src/match.c libssh/src/dh.c libssh/src/dh-gex.c libssh/src/legacy.c
SKIP += libssh/src/misc.c libssh/src/config.c
endif
CSRCS = $(filter-out $(SKIP), $(wildcard libssh/src/*.c libssh/src/external/*.c libssh/src/threads/*.c))

ifneq ($(CONFIG_UTILS_SSH),)
PROGNAME = scp ssh sshd
MAINSRC = libssh/examples/libssh_scp.c libssh/examples/ssh_client.c libssh/examples/ssh_server.c
CSRCS += libssh/examples/authentication.c libssh/examples/connect_ssh.c libssh/examples/knownhosts.c

PRIORITY = $(CONFIG_UTILS_SSH_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_SSH_STACKSIZE)
MODULE = $(CONFIG_UTILS_SSH)
endif

ifneq ($(CONFIG_TEST_SSH),)
LIBSSH_TEST_CONFIG = $(APPDIR)/external/libssh/libssh/tests/tests_config.h
context::
	@touch $(LIBSSH_TEST_CONFIG)
distclean::
	$(call DELFILE, $(LIBSSH_TEST_CONFIG))

PRIORITY = $(CONFIG_UTILS_SSH_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_SSH_STACKSIZE)
MODULE += $(CONFIG_TEST_SSH)

CSRCS += libssh/tests/torture_cmocka.c libssh/tests/torture_key.c libssh/tests/torture.c
CSRCS += libssh/tests/torture_pki.c
libssh/tests/torture.c_CFLAGS += -Dmain=unused_main -DTORTURE_SHARED
CFLAGS += -I $(APPDIR)/external/libssh/libssh/tests -I $(APPDIR)/external/libssh/libssh/src

PROGNAME += cmocka_libssh_buffer
MAINSRC += libssh/tests/unittests/torture_buffer.c
libssh/tests/unittests/torture_buffer.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_bytearray
MAINSRC += libssh/tests/unittests/torture_bytearray.c
libssh/tests/unittests/torture_bytearray.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_options
MAINSRC += libssh/tests/unittests/torture_options.c
libssh/tests/unittests/torture_options.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_packet_filter
MAINSRC += libssh/tests/unittests/torture_packet_filter.c
libssh/tests/unittests/torture_packet_filter.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_packet
MAINSRC += libssh/tests/unittests/torture_packet.c
libssh/tests/unittests/torture_packet.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_packet.c_CFLAGS += -Dkey=torture_packet_key -Div=torture_packet_iv

PROGNAME += cmocka_libssh_bind_config
MAINSRC += libssh/tests/unittests/torture_bind_config.c
libssh/tests/unittests/torture_bind_config.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_bind_config.c_CFLAGS += -Dtemplate=torture_bind_config_template

PROGNAME += cmocka_libssh_config
MAINSRC += libssh/tests/unittests/torture_config.c
libssh/tests/unittests/torture_config.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_callbacks
MAINSRC += libssh/tests/unittests/torture_callbacks.c
libssh/tests/unittests/torture_callbacks.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_crypto
MAINSRC += libssh/tests/unittests/torture_crypto.c
libssh/tests/unittests/torture_crypto.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_crypto.c_CFLAGS += -Dkey=torture_crypto_key

PROGNAME += cmocka_libssh_hashes
MAINSRC += libssh/tests/unittests/torture_hashes.c
libssh/tests/unittests/torture_hashes.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_init
MAINSRC += libssh/tests/unittests/torture_init.c
libssh/tests/unittests/torture_init.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_moduli
MAINSRC += libssh/tests/unittests/torture_moduli.c
libssh/tests/unittests/torture_moduli.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"

PROGNAME += cmocka_libssh_temp_dir
MAINSRC += libssh/tests/unittests/torture_temp_dir.c
libssh/tests/unittests/torture_temp_dir.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_temp_dir.c_CFLAGS += -Dtemplate=torture_temp_dir_template

PROGNAME += cmocka_libssh_temp_file
MAINSRC += libssh/tests/unittests/torture_temp_file.c
libssh/tests/unittests/torture_temp_file.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_temp_file.c_CFLAGS += -Dtemplate=torture_temp_file_template

PROGNAME += cmocka_libssh_threads_crypto
MAINSRC += libssh/tests/unittests/torture_threads_crypto.c
libssh/tests/unittests/torture_threads_crypto.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_threads_crypto.c_CFLAGS += -Dkey=torture_threads_crypto_key

PROGNAME += cmocka_libssh_misc
MAINSRC += libssh/tests/unittests/torture_misc.c
libssh/tests/unittests/torture_misc.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_misc.c_CFLAGS += -Dtemplate=torture_misc_template

PROGNAME += cmocka_libssh_push_pop_dir
MAINSRC += libssh/tests/unittests/torture_push_pop_dir.c
libssh/tests/unittests/torture_push_pop_dir.c_CFLAGS += -D"torture_run_tests(_)=main(int argc, char **argv)"
libssh/tests/unittests/torture_push_pop_dir.c_CFLAGS += -Dtemplate=torture_push_pop_dir_template
endif

include $(APPDIR)/Application.mk
