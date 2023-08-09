CC := gcc
CFLAGS := -Wall
LDFLAGS :=

ifeq ($(shell uname -s), Windows_NT)
    OUTPUT_DIR := build\examples
    EXECUTABLE_EXTENSION := .exe
else
    OUTPUT_DIR := build/examples
    EXECUTABLE_EXTENSION :=
    LDFLAGS := -lm
endif

SRC_DIR := examples
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
EXECUTABLES := $(patsubst $(SRC_DIR)/%.c,$(OUTPUT_DIR)/%$(EXECUTABLE_EXTENSION),$(SRC_FILES))

all: $(EXECUTABLES)

$(OUTPUT_DIR)/%$(EXECUTABLE_EXTENSION): $(SRC_DIR)/%.c | $(OUTPUT_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

$(OUTPUT_DIR):
	mkdir -p $(OUTPUT_DIR)

clean:
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean
