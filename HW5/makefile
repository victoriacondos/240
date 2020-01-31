CC = g++  # use g++ compiler

FLAGS = -std=c++11  # use C++ 11 standard
FLAGS += -Wall      # show all warnings
FLAGS += -g         # add debug info for gdb
FLAGS += -I inc     # include inc dir for preprocessor inclusions

LINK = $(CC) $(FLAGS) -o  # final linked build to binary executable

COMPILE = $(CC) $(FLAGS) -c  # compilation to intermediary .o files

test: bin/test1 bin/test2 bin/test3 bin/test4 bin/test5
	@./bin/test1
	@./bin/test2
	@./bin/test3
	@./bin/test4
	@./bin/test5

bin/test1 : lib/test1.o lib/point.o
	$(LINK) $@ $^
bin/test2 : lib/test2.o lib/point.o
	$(LINK) $@ $^
bin/test3 : lib/test3.o lib/point.o
	$(LINK) $@ $^
bin/test4 : lib/test4.o lib/point.o
	$(LINK) $@ $^
bin/test5 : lib/test5.o lib/point.o
	$(LINK) $@ $^


lib/test1.o : src/test_constructor.cc inc/test_point.h inc/point.h
	$(COMPILE) $< -o $@
lib/test2.o : src/test_assignment.cc inc/test_point.h inc/point.h
	$(COMPILE) $< -o $@
lib/test3.o : src/test_bracket.cc inc/test_point.h inc/point.h
	$(COMPILE) $< -o $@
lib/test4.o : src/test_equals.cc inc/test_point.h inc/point.h
	$(COMPILE) $< -o $@
lib/test5.o : src/test_calc_bounding_box.cc inc/test_point.h inc/point.h
	$(COMPILE) $< -o $@

lib/point.o : src/point.cc inc/point.h
	$(COMPILE) $< -o $@

clean:
	@rm -f lib/* bin/*
