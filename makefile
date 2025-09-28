CXX = g++
CXXFLAGS = -std=c++17 -Wall
TARGET = lfu
TEST_TARGET = lfu_test

all: $(TARGET)

$(TARGET): lfu.cpp
	$(CXX) $(CXXFLAGS) lfu.cpp -o $(TARGET)

$(TEST_TARGET): tests.cpp
	$(CXX) $(CXXFLAGS) tests.cpp -o $(TEST_TARGET)

run: $(TARGET)
	./$(TARGET)

run-file: $(TARGET)
	@echo "Запуск на файле: $(TEST)"
	./$(TARGET) < $(TEST)


test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

.PHONY: all run test clean