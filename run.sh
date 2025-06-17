#!/usr/bin/env bash
cxx=g++
src=$1
bin=${1%.*}
if [[ "$(uname)" == "Darwin" ]]; then
    cxx=g++-15
    bin=${bin}.bin
fi
flags_deprecated="\
-Wall \
-Wextra \
-Wpedantic \
-Werror \
-Wcast-align \
-Wcast-qual \
-Wdisabled-optimization \
-Wformat=2 \
-Wlogical-op \
-Wmissing-include-dirs \
-Woverloaded-virtual \
-Wpointer-arith \
-Wshadow \
-Wswitch-enum \
-Wvla \
-fno-ms-extensions \
"
flags="-Wall \
-Wextra \
-Wpedantic \
-Wshadow \
-Wformat=2 \
-Wfloat-equal \
-Wconversion \
-Wlogical-op \
-Wshift-overflow=2 \
-Wduplicated-cond \
-Wcast-qual \
-Wcast-align \
-Wvla \
-fno-ms-extensions \
-D_GLIBCXX_DEBUG \
-D_GLIBCXX_DEBUG_PEDANTIC \
-D_FORTIFY_SOURCE=2 \
"
# -fsanitize=address \
# -fsanitize=undefined \
# -fno-sanitize-recover \
# -fstack-protector \
$cxx $src -o $bin -std=c++14 -g $flags && $(realpath $bin)
