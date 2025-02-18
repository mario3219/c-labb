# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU’s libstdc++.
# -g is for debugging.
CPPFLAGS = -std=c++23 -I.
CXXFLAGS = -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS = -g

# Targets
PROGS = build words test_dictionary
all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
#build:
# /usr/share/dict

build: build.o trigrams.o
	$(CC) -o build build.o trigrams.o

words:
	./build < /usr/share/dict/words > words.txt
	rm build

spell: dictionary.o word.o trigrams.o spell.o
	$(CC) -std=c++23 -c edit_distance.cc
	$(CC) -std=c++23 -o spell dictionary.o word.o trigrams.o spell.o edit_distance.o

debug_spell: dictionary.o word.o trigrams.o spell.o
	$(CC) -std=c++23 -c edit_distance.cc
	$(CC) -std=c++23 -g -o debug_spell dictionary.o word.o trigrams.o spell.o edit_distance.o

test_dictionary: test_dictionary.o dictionary.o word.o trigrams.o
	$(CC) -std=c++23 -c edit_distance.cc
	$(CC) -std=c++23 -o test_dictionary test_dictionary.o dictionary.o word.o trigrams.o edit_distance.o

test_edit_distance: test_edit_distance.o
	$(CC) -g -c edit_distance.cc
	$(CC) -o test_edit_distance test_edit_distance.o edit_distance.o

debug_dictionary:
	$(CC) -g -c dictionary.cc
	$(CC) -g -c test_dictionary.cc
	$(CC) -g -o debug_dictionary dictionary.o test_dictionary.o
	gdb debug_dictionary

sanitize_dictionary:
	$(CC) $(CPPFLAGS) -c word.cc
	$(CC) $(CPPFLAGS) -c dictionary.cc
	$(CC) $(CPPFLAGS) -c test_dictionary.cc
	$(CC) $(CPPFLAGS) -c trigrams.cc
	$(CC) $(CPPFLAGS) -g -O1 -fsanitize=leak -o sanitize_dictionary dictionary.o test_dictionary.o word.o trigrams.o

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm words.txt

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
