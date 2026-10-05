CXX=g++
CXXFLAGS=-g -Wall -std=c++17 -pthread
TARGET = mt-collatz
SRC= mt-collatz.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS)-O $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) *.O

.PHONY: all clean 