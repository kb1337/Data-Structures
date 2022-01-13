#!/bin/sh

# Build program and run

set -e
# -e Exit immediately if a command exits with a non-zero status

CC=cc
CFLAGS="-Wall -Wextra"

$CC $CFLAGS -o doubly_linked_list main.c dll.c

./doubly_linked_list
