/*
 * makefile was created by Dr. Lewis & used to test my code. Copyright 2019.
 */
CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

base_decomposer : base_decomposer.o
        $(LINK) $@ $^

base_decomposer.o : base_decomposer.cc
        $(COMPILE) $^

test1 : base_decomposer
        python3 test_decomposer.py 1

test2 : base_decomposer
        python3 test_decomposer.py 2

test : test1 test2
        @echo "Tests Ran!"
