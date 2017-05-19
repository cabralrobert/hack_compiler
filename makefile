all: main

GCC = g++
BIN = bin

main: src/main.cpp
	$(GCC) src/main.cpp -o $(BIN)/app
