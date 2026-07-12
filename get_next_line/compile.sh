#!/bin/bash
read -p "Enter BUFFER_SIZE (default: 42): " BUFFER_SIZE_VALUE
if [ -z "$BUFFER_SIZE_VALUE" ]; then
    BUFFER_SIZE_VALUE=42
fi
OUTPUT_NAME="run_test"
SRC_FILES=$(find . -maxdepth 1 -name "*.c")

cc -Wall -Wextra -Werror -D BUFFER_SIZE=$BUFFER_SIZE_VALUE $SRC_FILES -o $OUTPUT_NAME