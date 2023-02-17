#! /bin/bash
set -e
g++ ./main.cpp -std=c++11 -o ./main.o
./main.o
