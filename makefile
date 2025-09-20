CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++20
MAIN = main.cpp
SRC = $(wildcard src/*.cpp)
OUT = main.exe

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(MAIN) $(SRC) -o $(OUT)

clean:
	del $(OUT)