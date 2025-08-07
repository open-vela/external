/****************************************************************************
 * external/open1722/argp.c
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <argp.h>

/****************************************************************************
 * static Functions
 ****************************************************************************/

static void print_help(const struct argp *argp, const char *program_name)
{
	const struct argp_option *opt = argp->options;

	if (program_name) {
		printf("Usage: %s [OPTIONS]...\n\n", program_name);
	}

	opt = argp->options;
	printf("Options:\n");

	while (opt->name || opt->key || opt->arg || opt->doc) {
		if (opt->key && opt->name) {
			if (opt->arg) {
				printf("  -%c, --%-20s=%-10s", opt->key,
				       opt->name, opt->arg);
			} else {
				printf("  -%c, --%-31s", opt->key, opt->name);
			}
		} else if (opt->key) {
			printf("  -%c, %-33s", opt->key, "");
		} else if (opt->name) {
			if (opt->arg) {
				printf("       --%-20s=%-10s", opt->name,
				       opt->arg);
			} else {
				printf("       --%-31s", opt->name);
			}
		} else {
			opt++;
			continue;
		}

		printf(" %s\n", opt->doc ? opt->doc : "");

		opt++;
	}

	printf("\n");
}

static void parse_long_option(struct argp *argp, char *arg,
			      struct argp_state *state)
{
	char *pos = strchr(arg, '=');
	char *value = NULL;
	size_t len = strlen(arg);
	const struct argp_option *opt = argp->options;

	if (pos) {
		len = pos - arg;
		value = pos + 1;
	} else {
		if (state->next < state->argc) {
			value = state->argv[state->next++];
		}
	}

	while (opt->name || opt->key || opt->arg || opt->doc) {
		if (opt->name && strncmp(opt->name, arg, len) == 0) {
			if (opt->arg && !value) {
				fprintf(stderr,
					"Option --%s requires an argument\n",
					opt->name);
				exit(EXIT_FAILURE);
			}

			argp->parser(opt->key, value, state);
			return;
		} else if (strcmp(arg, "help") == 0) {
			print_help(argp, state->argv[0]);
			exit(0);
		}

		opt++;
	}

	fprintf(stderr, "Unknown option: --%s\n", arg);
	print_help(argp, state->argv[0]);
	exit(EXIT_FAILURE);
}

static void parse_short_option(struct argp *argp, char *arg,
			       struct argp_state *state)
{
	char key = arg[0];
	char *value = NULL;
	const struct argp_option *opt = argp->options;

	if (arg[1] != '\0') {
		value = arg + 1;
	} else if (state->next < state->argc) {
		value = state->argv[state->next++];
	}

	while (opt->name || opt->key || opt->arg || opt->doc) {
		if (opt->key == key) {
			if (opt->arg && !value) {
				fprintf(stderr,
					"Option -%c requires an argument\n",
					key);
				exit(EXIT_FAILURE);
			}

			argp->parser(key, value, state);
			return;
		} else if (key == 'h') {
			print_help(argp, state->argv[0]);
			exit(0);
		}

		opt++;
	}

	fprintf(stderr, "Unknown option: -%c\n", key);
	print_help(argp, state->argv[0]);
	exit(EXIT_FAILURE);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

error_t argp_parse(struct argp *argp, int argc, char *argv[],
		   unsigned int flags, void *arg_index, void *input)
{
	struct argp_state state;
	state.argc = argc;
	state.argv = argv;
	state.flags = flags;
	state.input = input;
	state.next = 1;

	while (state.next < argc) {
		char *arg = argv[state.next];
		if (arg[0] != '-') {
			break;
		}

		state.next++;

		if (arg[1] == '-') {
			parse_long_option(argp, arg + 2, &state);
		} else {
			parse_short_option(argp, arg + 1, &state);
		}
	}

	return 0;
}
