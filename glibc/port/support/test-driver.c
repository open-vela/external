/****************************************************************************
 * apps/external/glibc/port/support/test-driver.c
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

/****************************************************************************
 * Public Functions
 ****************************************************************************/

int
main (int argc, char **argv)
{
  int status;
#ifdef TEST_FUNCTION
  status = TEST_FUNCTION ();
#else
  status = do_test ();
#endif

  if (!status)
    {
      printf ("%s done\n", __FUNCTION__);
    }

  return status;
}
