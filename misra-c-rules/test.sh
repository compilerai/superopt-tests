#!/bin/bash
if [ -z "$1" ]; then
  echo "Usage: ./test.sh <file_name>"
  exit 1
fi
clang "$1" -o a.out
if [ $? -ne 0 ]; then
  echo "Compilation failed"
  exit 1
fi
./a.out 
rm -f ./a.out