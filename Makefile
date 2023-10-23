# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Sources and Objects
SOURCES = $(wildcard $(SRC_DIR)/**/*.c $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Target executable
TARGET = $(BUILD_DIR)/pacman_game

# Build the target by default
all: $(TARGET)

# Link the object files into the target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(CFLAGS)

# Compile the source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ -I$(INCLUDE_DIR) $(CFLAGS)

# Clean up
clean:
	rm -rf $(BUILD_DIR)

# Run the game
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
