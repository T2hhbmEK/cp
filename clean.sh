#!/usr/bin/env bash

# Find and delete ELF binaries
find "$PWD" -type f -exec file {} + | grep -E 'ELF|executable' | grep -v 'text' | cut -d: -f1 | tee /dev/stderr | xargs -r rm -f

# Find and delete .exe files
find "$PWD" -type f -name "*.exe" | tee /dev/stderr | xargs -r rm -f

# Find and delete .dSYM folders
find "$PWD" -type d -name "*.dSYM" | tee /dev/stderr | xargs -r rm -rf
