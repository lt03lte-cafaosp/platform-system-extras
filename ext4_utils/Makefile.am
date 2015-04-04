AM_CFLAGS = -Wundef \
        -Wstrict-prototypes \
        -Wno-trigraphs \
        -g -O0 \
        -fno-inline \
        -fno-short-enums \
        -fpic \
        -DANDROID \
        -DHOST \
        $(LIBSELINUX_CFLAGS) \
        $(LIBSPARSE_CFLAGS)

AM_CPPFLAGS = $(AM_CFLAGS)

ACLOCAL_AMFLAGS = -I m4

### Build libsext4_utils library

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
    crc16.c \
    ext4_sb.c

libext4_utils_la_SOURCES = $(libext4_utils_c_sources)
libext4_utils_la_LDFLAGS = $(LIBSELINUX_LIBS) $(LIBSPARSE_LIBS)

lib_LTLIBRARIES = libext4_utils.la

### Build make_ext4fs binary

bin_PROGRAMS = make_ext4fs
make_ext4fs_CC = @CC@

make_ext4fs_SOURCES := make_ext4fs_main.c \
    canned_fs_config.c

make_ext4fs_CFLAGS = $(AM_CFLAGS)
make_ext4fs_CPPFLAGS = $(AM_CPPFLAGS)
make_ext4fs_LDADD = libext4_utils.la
