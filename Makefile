CC = g++
CFLAGS = -std=c++11 -Wall

# List of source files
SRCS = main.cpp function.cpp 

# List of dependent files
DEPS = function.h

# List of object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = word_test_project

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build object files
%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) 
 
