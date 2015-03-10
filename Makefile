#Define vars
CC = g++
FLAGS = -Wall -std=c++11
LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
EXEC = jankenpon
OBJ_FILES = main.o game_window.o menu.o game.o player.o enemy.o box.o

#Define the ALL scope (default)
all: clean game 

#Create the executable file
game : complex_components
	$(CC) -g -o $(EXEC) $(LIBS) $(OBJ_FILES) 

complex_components: basic_components
	$(CC) -g -c $(FLAGS) main.cpp game_window.cpp menu.cpp game.cpp 

basic_components:
	$(CC) -g -c $(FLAGS) box.cpp player.cpp enemy.cpp

clean: 
	rm -f *.o $(EXEC)
