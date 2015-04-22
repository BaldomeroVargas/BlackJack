COMP=g++
FLAGS=-g

all: player deck interface
	$(COMP) $(FLAGS) -std=c++11 main.cpp -o black.out Player.o Deck.o
	
main:
	$(COMP) $(FLAGS) -std=c++11 main.cpp -o black.out	
	
player:
	$(COMP) $(FLAGS) -std=c++11 -c Player.cpp
	
deck:
	$(COMP) $(FLAGS) -std=c++11 -c Deck.cpp
	
interface:
	$(COMP) $(FLAGS) -std=c++11 -c Interface.cpp
	
clean:
	rm -fv Interface.o Player.o Deck.o black.out
	
run:
	./black.out rules.txt
	