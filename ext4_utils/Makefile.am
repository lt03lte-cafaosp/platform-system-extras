libext4_utils_a_CFLAGS = -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic \
        -DANDROID \
        -DHAVE_ANDROID_OS \
        $(LIBSELINUX_CFLAGS)

ACLOCAL_AMFLAGS = -I m4

### Build libsext4_utils library

libext4utilsincludedir = $(includedir)
libext4utilsinclude_HEADERS = make_ext4fs.h ext4_utils.h ext4.h

libext4_utils_c_sources :=  make_ext4fs.c \
	ext4fixup.c \
	ext4_utils.c \
	allocate.c \
	contents.c \
	extent.c \
	indirect.c \
	uuid.c \
	sha1.c \
	wipe.c \
	crc16.c

libext4_utils_a_SOURCES = $(libext4_utils_c_sources)
libext4_utils_a_LDFLAGS = -lsparse -lselinux

lib_LIBRARIES = libext4_utils.a

bin_PROGRAMS = make_ext4fs
make_ext4fs_SOURCES = make_ext4fs_main.c \
	make_ext4fs.c \
	ext4fixup.c \
	ext4_utils.c \
	allocate.c \
	contents.c \
	extent.c \
	indirect.c \
	uuid.c \
	sha1.c \
	wipe.c \
	crc16.c
make_ext4fs_CFLAGS = -Iinclude -DHOST $(LIBSPARSE_CFLAGS)
make_ext4fs_LDADD = -lz -lselinux $(LIBSPARSE_LIBS)
