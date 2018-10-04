# the compiler: gcc for C program, define as g++ for C++
CC = g++

CFLAGS  = -g -Wall

LIBS = -l uuid -l sqlite3

INC = ./inc
OBJ = ./obj
BIN = ./bin
SRC = ./src

INCLUDES = -I $(INC)
OBJECTS =  $(OBJ)/main.o $(OBJ)/utility.o $(OBJ)/login.o $(OBJ)/uuid.o

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(INCLUDES) $(CFLAGS) $(LIBS) -o $(BIN)/$(TARGET) $(OBJECTS)


$(OBJ)/main.o: 
	$(CC) $(INCLUDES) $(CFLAGS) $(LIBS) -c -o $(OBJ)/main.o ./main.cpp

$(OBJ)/login.o: $(OBJ)/utility.o
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $(OBJ)/login.o $(SRC)/login.cpp

$(OBJ)/utility.o: 
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $(OBJ)/utility.o $(SRC)/utility.cpp

$(OBJ)/uuid.o:
	$(CC) $(INCLUDES) $(CFLAGS) -c -o $(OBJ)/uuid.o $(SRC)/uuid.cpp

clean:
	$(RM) $(BIN)/$(TARGET)
	$(RM) $(OBJ)/*.o
	$(RM) core
