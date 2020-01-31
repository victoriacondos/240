CC = g++  # use g++ compiler

FLAGS = -std=c++11  # compile with C++ 11 standard
FLAGS += -Wall      # compile with all warnings

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files


test_all: test
	./test 0
	./test 1
	./test 2
	./test 3
	./test 4
	./test 5

test: comp_geo.o test.o
	$(LINK) $@ $^

test.o : test.cc comp_geo.h
	$(COMPILE) $<

comp_geo.o : comp_geo.cc comp_geo.h
	$(COMPILE) $< 

clean:
	@rm test *.o

