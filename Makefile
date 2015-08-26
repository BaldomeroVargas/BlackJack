COMP=g++
FLAGS=-g

all: player deck
	$(COMP) $(FLAGS) -std=c++11 main.cpp -o black.out Player.o Deck.o
	
main:
	$(COMP) $(FLAGS) -std=c++11 main.cpp -o black.out	
	
player:
	$(COMP) $(FLAGS) -std=c++11 -c Player.cpp
	
deck:
	$(COMP) $(FLAGS) -std=c++11 -c Deck.cpp
	
clean:
	rm -fv Player.o Deck.o black.out
	
run:
	./black.out
	
