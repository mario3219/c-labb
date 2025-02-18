CC = g++
CFLAGS = -Wall -Wextra -MMD -g
SRCS = coding.cc test_coding.cc
OBJS = $(SRCS:.cc=.o)
DEPS = $(SRCS:.cc=.d)

# Build the executable
program: $(OBJS)
	$(CC) -o test_coding $(OBJS)
	./test_coding

encode: $(OBJS)
	$(CC) -o encode encode.cc coding.cc
	rm -f encodedtext.enc
	./encode < mytext.txt > encodedtext.enc

decode: $(OBJS)
	$(CC) -o decode decode.cc coding.cc
	rm -f decodedtext.enc
	./decode < encodedtext.enc > decodedtext.enc

testing: coding.cc
	$(CC) -o $(CXXFLAGS) testing coding.cc
	./testing

# Compile source files
%.o: %.cc
	$(CC) $(CFLAGS) -c $< -o $@

# Include the dependency files if they exist
-include $(DEPS)

# Clean rule
.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) test_coding testing coding encode decode encodedtext.enc decodedtext.enc