// Author: David Blei (blei@cs.princeton.edu)
//
// Copyright 2006 David Blei
// All Rights Reserved.
//
// See the README for this package for details about modifying or
// distributing this software.

#ifndef PARAMSH
#define PARAMSH

#define MAX_LINE_LENGTH 100000;

#include "gsl-wrappers.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <gsl/gsl_vector.h>

void params_read_string(FILE* f, char const * name, char const * x);

void params_read_int(FILE* f, char const * name, int* x);

void params_write_int(FILE *, char const *, int);

void params_read_double(FILE* f, char const * name, double* x);

void params_write_double(FILE *, char const *, double);

void params_read_gsl_vector(FILE* f, char const * name, gsl_vector** x);

void params_write_gsl_vector(FILE *, char const * , gsl_vector *);

void params_write_gsl_vector_multiline(FILE *, char const * , gsl_vector *);

void params_write_gsl_matrix(FILE *, char const * , gsl_matrix *);

void params_write_sparse_gsl_matrix(FILE *, char const * , gsl_matrix *);

#endif
