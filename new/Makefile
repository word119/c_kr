# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lreadline

# Target executable
TARGET = shell

# Source files
SRCS = shell.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the build (remove object files and the executable)
clean:
	rm -f $(OBJS) $(TARGET)

# Add to avoid error when clean is called without existing targets
.PHONY: all clean
