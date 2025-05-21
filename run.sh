#!/usr/bin/env bash
src=$1
bin=${1%.*}
clang++ $src -o $bin -static -Wall -O2 && $(realpath $bin)
