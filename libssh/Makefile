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

CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" .}
CFLAGS += ${shell $(INCDIR) $(INCDIROPT) "$(CC)" $(APPDIR)/external/zlib/zlib}

CFLAGS += -DTHREAD_STACKSIZE=CONFIG_UTILS_SSH_STACKSIZE
CFLAGS += -DBLOCKSIZE=4096 -DBUF_SIZE=4096 -DCHUNKSIZE=4096
CFLAGS += -DERROR_BUFFERLEN=512 -DLOG_SIZE=256 -DMAX_LINE_SIZE=512
CFLAGS += -Dmd5_init=sshmd5_init -Dmd5_update=sshmd5_update -Dmd5_final=sshmd5_final
CFLAGS += -Wno-deprecated-declarations

SKIP  = libssh/src/dh_crypto.c libssh/src/ecdh_crypto.c libssh/src/ecdh_gcrypt.c
SKIP += libssh/src/gcrypt_missing.c libssh/src/getrandom_crypto.c
SKIP += libssh/src/getrandom_gcrypt.c libssh/src/gssapi.c libssh/src/libcrypto.c
SKIP += libssh/src/libcrypto-compat.c libssh/src/libgcrypt.c libssh/src/md_crypto.c
SKIP += libssh/src/md_gcrypt.c libssh/src/pki_crypto.c libssh/src/pki_gcrypt.c
SKIP += libssh/src/threads/libcrypto.c libssh/src/threads/libgcrypt.c libssh/src/threads/winlocks.c
CSRCS = $(filter-out $(SKIP), $(wildcard libssh/src/*.c libssh/src/external/*.c libssh/src/threads/*.c))

ifneq ($(CONFIG_UTILS_SSH),)
PROGNAME = scp ssh sshd
MAINSRC = libssh/examples/libssh_scp.c libssh/examples/ssh_client.c libssh/examples/ssh_server.c
CSRCS += libssh/examples/authentication.c libssh/examples/connect_ssh.c libssh/examples/knownhosts.c

PRIORITY = $(CONFIG_UTILS_SSH_PRIORITY)
STACKSIZE = $(CONFIG_UTILS_SSH_STACKSIZE)
MODULE = $(CONFIG_UTILS_SSH)
endif

include $(APPDIR)/Application.mk
