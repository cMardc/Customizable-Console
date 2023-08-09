# Determine the operating system
ifeq ($(OS),Windows_NT)
    PLATFORM := Windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM := Linux
    endif
endif

# Set source and output directories based on the platform
ifeq ($(PLATFORM),Windows)
    SOURCE_DIR := examples/Windows
    OUTPUT_DIR := build/examples/Windows
    CC := gcc
else
    SOURCE_DIR := examples/Linux
    OUTPUT_DIR := build/examples/Linux
    CC := gcc -lm
endif

# Source files to compile
SOURCE_FILES := $(wildcard $(SOURCE_DIR)/*.c)
OBJ_FILES := $(patsubst $(SOURCE_DIR)/%.c, $(OUTPUT_DIR)/%.o, $(SOURCE_FILES))

# Target for building all objects
all: $(OBJ_FILES)

# Rule for compiling source files to object files
$(OUTPUT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OUTPUT_DIR)
	$(CC) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -rf $(OUTPUT_DIR)
