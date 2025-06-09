#!/usr/bin/env bash
src=$1
bin=${1%.*}
flags="\
-Wall \
-Wextra \
-Wpedantic \
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
g++ $src -o $bin -std=c++14 -O2 -static $flags && $(realpath $bin)
