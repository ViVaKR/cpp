#!/bin/sh

$(which g++-12) -g -std=c++23 VivMain.cpp -o main

./main
