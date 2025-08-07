/****************************************************************************
 * external//nuttx/argp.h
 *
 *   Copyright (C) 2025 Xiaomi InC. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __ARGP_H
#define __ARGP_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

struct argp_state;

typedef int error_t;
typedef error_t (*argp_parser_t)(int key, char *arg, struct argp_state *state);

/****************************************************************************
 * Public Type Definitions
 ****************************************************************************/

struct argp_option {
	const char *name; /* Option name */
	int key; /* Option key (usually a character) */
	const char *arg; /* Argument for the option (if any) */
	int flags; /* Flags for the option (e.g., ARGP_NO_ARGS) */
	const char *doc; /* Documentation for the option */
};

struct argp_state {
	int argc; /* Number of arguments */
	char **argv; /* argv array */
	int next; /* Index of the next argument to be parsed */
	int flags; /* Flags for the state (e.g., ARGP_NO_ARGS) */
	void *input; /* Input data for the parser */
};

struct argp {
	const struct argp_option *options; /* Array of options */
	argp_parser_t parser; /* Function to parse options */
	const char *program_name; /* Program name */
	const char *short_doc; /* Short documentation */
	const char *long_doc; /* Long documentation */
};

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

error_t argp_parse(struct argp *argp, int argc, char *argv[],
		   unsigned int flags, void *arg_index, void *input);

#endif /* __ARGP_H */
