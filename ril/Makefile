include $(APPDIR)/Make.defs

CFLAGS += ${INCDIR_PREFIX}ril/libril
CFLAGS += ${INCDIR_PREFIX}ril/librilutils
ifneq ($(CONFIG_GOLDFISH_RIL),)
CFLAGS += ${INCDIR_PREFIX}ril/reference-ril
endif

CXXEXT:= .cpp
CXXFLAGS += ${INCDIR_PREFIX}ril/libril
CXXFLAGS += ${INCDIR_PREFIX}ril/librilutils

CXXSRCS += ril/libril/ril.cpp
CXXSRCS += ril/libril/parcel.cpp
CXXSRCS += ril/libril/ril_event.cpp

CSRCS += $(wildcard ril/librilutils/*.c)

ifneq ($(CONFIG_GOLDFISH_RIL),)
CSRCS += $(wildcard ril/reference-ril/*.c)

advancedFeatures:
	@echo "ModemSimulator = on" > ../../nuttx/advancedFeatures.ini

context:: advancedFeatures

clean::
	$(call DELFILE, ../../nuttx/advancedFeatures.ini)
endif

PRIORITY  += $(CONFIG_RILD_PRIORITY)
STACKSIZE += $(CONFIG_RILD_STACKSIZE)
PROGNAME  += rild
MAINSRC   += ril/rild/rild.c

ifneq ($(CONFIG_RIL_TEST),)
CXXEXT:= .cpp
CXXSRCS += ril/riltest/ril_parcel_ctor_verifier.cpp

PRIORITY  += $(CONFIG_RIL_TEST_PRIORITY)
STACKSIZE += $(CONFIG_RIL_TEST_STACKSIZE)
PROGNAME  += rilreq_tool
MAINSRC   += ril/riltest/rilreq_tool.cpp
endif

include $(APPDIR)/Application.mk
