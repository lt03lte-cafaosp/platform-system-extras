  AC_PREREQ(2.61)

  AC_INIT([ext4-utils],1.0.0)

  AM_INIT_AUTOMAKE([foreign])

  AM_MAINTAINER_MODE

  AC_CONFIG_HEADER([config.h])
  AC_CONFIG_MACRO_DIR([m4])

  # Checks for programs.
  AM_PROG_AS
  AC_PROG_CC
  AM_PROG_CC_C_O
  AC_PROG_LIBTOOL
  AC_PROG_AWK
  AC_PROG_CPP
  AC_PROG_CXX
  AC_PROG_INSTALL
  AC_PROG_LN_S
  AC_PROG_MAKE_SET

  #
  # Build all components by default
  #
  # To add new components: add AC_ARG_ENABLE, AM_CONDITIONAL and update AC_OUTPUT
  #

  # Checks for libraries.
  PKG_CHECK_MODULES([LIBSELINUX], [libselinux])
  AC_SUBST([LIBSELINUX_CFLAGS])
  AC_SUBST([LIBSELINUX_LIBS])

  PKG_CHECK_MODULES([LIBSPARSE], [libsparse])
  AC_SUBST([LIBSPARSE_CFLAGS])
  AC_SUBST([LIBSPARSE_LIBS])

  AC_ARG_WITH([core_includes],
        AC_HELP_STRING([--with-core-includes=@<:@dir@:>@],
           [Specify the location of the core headers]),
        [core_incdir=$withval],
        with_core_includes=no)

  if test "x$with_core_includes" != "xno"; then
     CFLAGS="${CFLAGS} -I${core_incdir}"
  fi

  AC_SUBST([CFLAGS])

  AC_OUTPUT([ \
          Makefile \
  ])
