#include <sys/endian.h>

#define PCI_CONFIG_H
#define PCI_HAVE_64BIT_ADDRESS
#define PCI_IDS "pci.ids.gz"
#define PCILIB_VERSION "3.12.0"
#define PCI_HAVE_PM_OBSD_DEVICE
#define PCI_HAVE_PM_DUMP
#define PCI_PATH_OBSD_DEVICE "/dev/pci"
#define PCI_PATH_IDS_DIR "/etc"
#define xmalloc pciutils_xmalloc
#define xrealloc pciutils_xrealloc
#define xstrdup pciutils_xstrdup
