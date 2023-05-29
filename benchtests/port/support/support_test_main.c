/****************************************************************************
 * apps/external/benchtests/port/support/support_test_main.c
 *
 * Main worker function for the test driver.
 * Copyright (C) 1998-2023 Free Software Foundation, Inc.
 * This file is part of the GNU C Library.
 *
 * The GNU C Library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * The GNU C Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with the GNU C Library; if not, see
 * <https://www.gnu.org/licenses/>.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <support/test-driver.h>
#include <support/support_test_main.h>

#include <assert.h>
#include <errno.h>
#include <getopt.h>
#include <malloc.h>
#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/param.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Name: run_test_function
 ****************************************************************************/

static int run_test_function(int argc, char **argv,
                             const struct test_config *config)
{
  if (config->run_command_mode)
    {
      /* In run-command-mode, the child process executes the command line
       * arguments as a new program.
       */

      char **argv_ = malloc(sizeof (char *) *argc);
      memcpy(argv_, &argv[1], sizeof (char *) *(argc - 1));
      argv_[argc - 1] = NULL;
      execv(argv_[0], argv_);
      printf("error: should not return here\n");
      exit(1);
    }

  if (config->test_function != NULL)
    {
      return config->test_function();
    }
  else if (config->test_function_argv != NULL)
    {
      return config->test_function_argv(argc, argv);
    }
  else
    {
      printf("error: no test function defined\n");
      exit(1);
    }
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: support_test_main
 ****************************************************************************/

int support_test_main(int argc, char **argv,
                      const struct test_config *config)
{
  /* Correct for the possible parameters.  */

  argv[optind - 1] = argv[0];
  argv += optind - 1;
  argc -= optind - 1;

  /* Call the initializing function, if one is available.  */

  if (config->prepare_function != NULL)
    {
      config->prepare_function(argc, argv);
    }

  return run_test_function(argc, argv, config);
}
