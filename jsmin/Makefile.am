#                                        -*- Automake -*-
# Process this file with automake to produce Makefile.in.

# library definition
lib_LTLIBRARIES = libjsmin.la
libjsmin_la_SOURCES = libjsmin.c
libjsmin_la_CPPFLAGS = -I$(top_srcdir)
libjsmin_la_LDFLAGS = -version-info $(LT_CURRENT):$(LT_REVISION):$(LT_AGE)

# program definition
bin_PROGRAMS = jsmin
jsmin_SOURCES = jsmin.c
jsmin_CPPFLAGS = -I$(top_srcdir)
jsmin_LDADD = libjsmin.la

# install development headers
pkgincludedir = $(includedir)/jsmin
pkginclude_HEADERS = jsmin.h
