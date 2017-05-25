all: folder app

GCC = g++
BIN = bin
OBJ = obj

app: main function arquivo typeA typeC
	$(GCC) -o $(BIN)/app $(OBJ)/main.o $(OBJ)/functions.o $(OBJ)/arquivo.o $(OBJ)/typeA.o $(OBJ)/typeC.o

main: src/main.cpp
	$(GCC) src/main.cpp -Iinc/ -c -o $(OBJ)/main.o

function: src/functions.cpp
	$(GCC) src/functions.cpp -Iinc/ -c -o $(OBJ)/functions.o

arquivo: src/arquivo.cpp
	$(GCC) src/arquivo.cpp -Iinc/ -c -o $(OBJ)/arquivo.o

typeA: src/typeA.cpp
	$(GCC) src/typeA.cpp -Iinc/ -c -o $(OBJ)/typeA.o

typeC: src/typeC.cpp
	$(GCC) src/typeC.cpp -Iinc/ -c -o $(OBJ)/typeC.o

folder:
	mkdir -p $(OBJ) $(BIN) data

clean:
	rm -rf $(OBJ)/* $(BIN)/* $(OBJ) $(BIN)
