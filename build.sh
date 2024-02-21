#!/bin/bash
gcc main.c -Wall -Wextra -pedantic -std=c11 -ggdb -lm -lraylib -lGL -lpthread -ldl -lrt -lX11  -o main
