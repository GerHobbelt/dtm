// Author: David Blei (blei@cs.princeton.edu)
//
// Copyright 2006 David Blei
// All Rights Reserved.
//
// See the README for this package for details about modifying or
// distributing this software.

#ifndef _UTIL_INCLUDED
#define _UTIL_INCLUDED 1

#include "flags.hpp"

#include <stdexcept>
#include <stdarg.h>

#define EOS  '\0'
#define CRLF  printf("\n")
#define TRUE  1
#define FALSE 0

extern const char*  quote (char const *s);
extern const char*  dequote (char const *s);
extern void   quote_no_matter_what (char const *s, char *t);
extern int    verify (char const *s, char const *t);
extern char*  strip (char *s);
extern char*  upper (char *s);
extern char*  lower (char *s);
extern int    qfilef (char const *fname); /* TRUE if file exists */
extern int    free_storage (char const *fn); /* returns free storage in file system of fn */
extern char*  util_strdup(char const *string);
extern void*  util_malloc (int size);
extern void*  util_realloc (void *p, int size);
extern void*  util_calloc (int num, int size);
extern void   util_free (void *p);
extern int    util_space_in_use (void);
extern int    util_pointers_in_use (void);
extern void error(char const *fmt, ...);

#endif
