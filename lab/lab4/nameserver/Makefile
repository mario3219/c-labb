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
PROGS = vns_test
PROGS_H = vns

# Targets rely on implicit rules for compiling and linking
#build:
# /usr/share/dict

vns:
	$(CC) -c $(CXXFLAGS) vns.h

vns_test: vns_test.o

mns:
	$(CC) -c $(CXXFLAGS) mns.h

mns_test: mns_test.o

umns:
	$(CC) -c $(CXXFLAGS) umns.h

umns_test: umns_test.o

# Phony targets
.PHONY: all clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm -f *.h.gch $(PROGS_H)
	rm $(PROGS)

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
