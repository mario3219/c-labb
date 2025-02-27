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
PROGS = simplebitsettest bitsettest1 bitsettest2

# Compile executables

simplebitsettest: simplebitsettest.o simplebitset.o

bitsettest1: bitsettest1.o bitset.o bitreference.o

bitsettest2: bitsettest2.o bitset.o bitreference.o

# Test-compiling for errors

bitset:
	$(CC) $(CXXFLAGS) -c bitset.cc

bitreference:
	$(CC) $(CXXFLAGS) -c bitreference.cc

bitsetiterator:
	$(CC) $(CXXFLAGS) -c bitsetiterator.cc

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o
	rm -f *.h.gch

distclean: clean
	rm *.d
	rm $(PROGS)

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
