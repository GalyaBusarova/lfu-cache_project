CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = lfu

all: $(TARGET)

$(TARGET): lfu.cpp tests.cpp
	$(CXX) $(CXXFLAGS) lfu.cpp tests.cpp -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean