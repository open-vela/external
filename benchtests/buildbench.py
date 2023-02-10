 #***************************************************************************
 # apps/external/benchtests/buildbench.py
 #
 # Licensed to the Apache Software Foundation (ASF) under one or more
 # contributor license agreements.  See the NOTICE file distributed with
 # this work for additional information regarding copyright ownership.  The
 # ASF licenses this file to you under the Apache License, Version 2.0 (the
 # "License"); you may not use this file except in compliance with the
 # License.  You may obtain a copy of the License at
 #
 #   http://www.apache.org/licenses/LICENSE-2.0
 #
 # Unless required by applicable law or agreed to in writing, software
 # distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 # WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 # License for the specific language governing permissions and limitations
 # under the License.
 #
 #****************************************************************************

import os
import sys

bench_math    = ['acos', 'acosh', 'asin', 'asinh', 'atan', 'atan2', 'atanh', 'cbrt', 'cos', 'cosf', 'cosh', 'erf', 'erfc', 'exp', 'exp10', 'exp10f', 'exp2', 'exp2f', 'expf', 'expm1', 'fmax', 'fmaxf', 'fmin', 'fminf', 'hypot', 'hypotf', 'ilogb', 'ilogbf', 'isfinite', 'isinf', 'isnan', 'j0', 'j1', 'lgamma', 'log', 'log10', 'log1p', 'log2', 'log2f', 'logb', 'logbf', 'logf', 'modf', 'pow', 'powf', 'rint', 'roundeven', 'roundevenf', 'sin', 'sincos', 'sincosf', 'sinf', 'sinh', 'sqrt', 'tan', 'tanh', 'tgamma', 'trunc', 'truncf', 'y0', 'y1', 'cbrtl']
bench_pthread = ['pthread_once', 'thread_create']
bench_string  = ['ffs', 'ffsll']
stdio_common_benchset = ['sprintf']

scriptPath = "scripts/bench.py"

os.chdir("benchtests")

def main(args):
  if args == "bench-math":
    benchcase = bench_math
  if args == "bench-pthread":
    benchcase = bench_pthread
  if args == "bench-string":
    benchcase = bench_string
  if args == "stdio-common-benchset":
    benchcase = stdio_common_benchset

  for i in range(0, len(benchcase)):
    outputFile = args + "-" + benchcase[i]+".c"
    cmd ="python " + scriptPath + " " + benchcase[i] + " " + "> "  + outputFile
    os.system(cmd)

  return os.EX_OK

if __name__ == "__main__":
  sys.exit(main(sys.argv[1]))
