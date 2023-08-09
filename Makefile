CXX = g++
CC = gcc
CXXFLAGS = -Wall -O2 
SRC_DIR = examples
BUILD_DIR = build/examples

# Get a list of all source files in the examples directory
SOURCES = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*.cpp)

# Convert source file paths to corresponding output file paths in build directory
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES)))
EXECUTABLES = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%,$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%,$(SOURCES)))

all: $(EXECUTABLES)

$(BUILD_DIR)/%: $(BUILD_DIR)/%.o
	$(CXX) $(CXXFLAGS) -o $@ $< -lm

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
