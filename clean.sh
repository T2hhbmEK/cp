#!/usr/bin/env bash

# Find and delete ELF binaries
find . -type f ! -name "*.*" -exec file {} + | grep 'ELF' | cut -d: -f1 | xargs rm -f
find . -type f -name "*.out" -exec file {} + | grep 'ELF' | cut -d: -f1 | xargs rm -f

# Find and delete .exe files
find . -type f -name "*.exe" -exec rm -f {} +
