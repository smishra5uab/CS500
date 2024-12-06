# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I/usr/include/eigen3
LDFLAGS = -lgtest -lgtest_main -pthread

# Directories
SRC_DIR = .
BUILD_DIR = build
SRC_FILES = hamming.cpp main.cpp hamming_test.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
OBJ_PATHS = $(addprefix $(BUILD_DIR)/, $(OBJ_FILES))

# Executables
EXEC_DECODER = $(BUILD_DIR)/hamming_decoder
EXEC_TEST = $(BUILD_DIR)/hamming_test

# Default target (build both executables)
all: $(EXEC_DECODER) $(EXEC_TEST)

# Rule for decoding executable
$(EXEC_DECODER): $(BUILD_DIR)/hamming.o $(BUILD_DIR)/main.o
	$(CXX) $(BUILD_DIR)/hamming.o $(BUILD_DIR)/main.o -o $@

# Rule for test executable
$(EXEC_TEST): $(BUILD_DIR)/hamming.o $(BUILD_DIR)/hamming_test.o
	$(CXX) $(BUILD_DIR)/hamming.o $(BUILD_DIR)/hamming_test.o -o $@ $(LDFLAGS)

# Rule to compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build directory (remove .o and executables)
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC_DECODER) $(EXEC_TEST)

# Run tests using the test executable
test: $(EXEC_TEST)
	./$(EXEC_TEST)

.PHONY: all clean test




# # Compiler and Flags
# CXX = g++
# CXXFLAGS = -std=c++11 -Wall -Wextra -I/usr/include/eigen3
# LDFLAGS = -lgtest -lgtest_main -pthread

# # Project files
# SRCS = hamming.cpp main.cpp
# TEST_SRCS = hamming_test.cpp hamming.cpp
# OBJS = hamming.o main.o
# TEST_OBJS = hamming_test.o hamming.o

# # Targets
# all: hamming_decoder hamming_test

# # Build the main program (hamming_decoder)
# hamming_decoder: $(OBJS)
# 	$(CXX) $(CXXFLAGS) -o $@ $^

# # Build the test program (hamming_test)
# hamming_test: $(TEST_OBJS)
# 	$(CXX) $(CXXFLAGS) $(TEST_OBJS) -o $@ $(LDFLAGS)

# # Compile the object files for the main program
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Compile the object files for the test program
# $(TEST_OBJS): hamming.o hamming_test.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Clean up the build artifacts
# clean:
# 	rm -f *.o hamming_decoder hamming_test

# # Run tests (assuming the tests are defined in the hamming_test binary)
# test: hamming_test
# 	./hamming_test

# .PHONY: all clean test


