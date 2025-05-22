#!/usr/bin/env bash

# Find and delete ELF binaries
find $CWD -type f ! -name "*.*" -exec file {} + | grep 'ELF' | cut -d: -f1 | tee /dev/stderr | xargs rm -f
find $CWD -type f -name "*.out" -exec file {} + | grep 'ELF' | cut -d: -f1 | tee /dev/stderr | xargs rm -f

# Find and delete .exe files
find $CWD -type f -name "*.exe" -print0 | tee /dev/stderr | xargs rm -f
