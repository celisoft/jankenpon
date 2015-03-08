#Define vars
CC = g++
FLAGS = -Wall -std=c++11
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
EXEC = jankenpon
OBJ_FILES = main.o game_window.o menu.o game.o player.o box.o

#Define the ALL scope (default)
all: clean game 

#Create the executable file
game : components
	$(CC) -o $(EXEC) $(LIBS) $(OBJ_FILES) 

components:
	$(CC) -c $(FLAGS) main.cpp game_window.cpp menu.cpp game.cpp box.cpp player.cpp

clean: 
	rm -f *.o $(EXEC)
