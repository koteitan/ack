.PHONY:clean all

TARGET = ack
OBJ = ack.o
CXXFLAGS = -g3 -O0
CC = gcc

all: $(TARGET)

TARGET:$(OBJ)
	gcc $(OBJ) -o $(TARGET)

clean:
	rm -rf $(TARGET) .o
