#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

# Initialize autoconf
AC_PREREQ([2.59])

# Library versioning
# Making releases:
#	jsmin_micro_version += 1
#	jsmin_interface_age += 1
# If functions have been added or backward-compatibility has been broken:
#	jsmin_interface_age = 0
m4_define([jsmin_major_version], [0])
m4_define([jsmin_minor_version], [1])
m4_define([jsmin_micro_version], [0])
m4_define([jsmin_interface_age], [0])

# Initialize autoconf & automake
AC_INIT([JSMin], [jsmin_major_version.jsmin_minor_version.jsmin_micro_version],
	[https://github.com/douglascrockford/JSMin/issues], [jsmin])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.9 foreign -Wno-portability nostdinc])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_SRCDIR([jsmin/jsmin.c])

# Initialize Libtool
LT_PREREQ([2.2])
LT_INIT([disable-static])

# Checks for programs
AC_PROG_CC
PKG_PROG_PKG_CONFIG([0.17])

# Enable compiler flags
AX_TRY_CFLAGS([-Wall], [AX_CFLAGS([-Wall])])
AX_TRY_CFLAGS([-Wstrict-prototypes], [AX_CFLAGS([-Wstrict-prototypes])])
AX_TRY_CFLAGS([-Wcast-align], [AX_CFLAGS([-Wcast-align])])
AX_TRY_CFLAGS([-fno-common], [AX_CFLAGS([-fno-common])])

# Libtool versioning
LT_CURRENT=m4_eval(100 * jsmin_minor_version + jsmin_micro_version - jsmin_interface_age)
LT_REVISION=jsmin_interface_age
LT_AGE=m4_eval(m4_eval(100 * jsmin_minor_version + jsmin_micro_version) - jsmin_interface_age)
AC_SUBST([LT_CURRENT])
AC_SUBST([LT_REVISION])
AC_SUBST([LT_AGE])

# Output files
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
	jsmin/Makefile
	libjsmin.pc
	Makefile
])
AC_OUTPUT
AC_MSG_RESULT([
$PACKAGE_NAME build options:
	Host: $host
	Version: $VERSION
])
