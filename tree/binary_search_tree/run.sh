#!/bin/sh

# Build program and run

set -e
# -e Exit immediately if a command exits with a non-zero status

CC=cc
CFLAGS="-Wall -Wextra"

$CC $CFLAGS -o binary_search_tree main.c bst.c

./binary_search_tree
