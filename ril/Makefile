include $(APPDIR)/Make.defs

CFLAGS += ${INCDIR_PREFIX}ril/include
CFLAGS += ${INCDIR_PREFIX}ril/include/telephony
CFLAGS += ${INCDIR_PREFIX}ril/libril
CFLAGS += ${INCDIR_PREFIX}ril/librilutils
CFLAGS += ${INCDIR_PREFIX}ril/reference-ril

CXXEXT:= .cpp
CXXFLAGS += ${INCDIR_PREFIX}ril/include
CXXFLAGS += ${INCDIR_PREFIX}ril/include/telephony
CXXFLAGS += ${INCDIR_PREFIX}ril/libril
CXXFLAGS += ${INCDIR_PREFIX}ril/librilutils

CXXSRCS += ril/libril/ril.cpp
CXXSRCS += ril/libril/ril_event.cpp

CSRCS += $(wildcard ril/librilutils/*.c)

CSRCS += ril/reference-ril/at_tok.c
CSRCS += ril/reference-ril/atchannel.c
CSRCS += ril/reference-ril/misc.c
CSRCS += ril/reference-ril/reference-ril.c

PRIORITY  += $(CONFIG_GOLDFISH_RILD_PRIORITY)
STACKSIZE += $(CONFIG_GOLDFISH_RILD_STACKSIZE)
PROGNAME  += rild
MAINSRC   += ril/rild/rild.c

include $(APPDIR)/Application.mk
