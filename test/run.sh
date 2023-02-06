#!/bin/bash

rm -rf *.o test;
make -s && ./test
#g++ -std=c++98 test_random_access_iterator.cpp && ./a.out