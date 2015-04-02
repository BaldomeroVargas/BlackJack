COMP=g++
FLAGS=-g

all: player deck interface
	$(COMP) $(FLAGS) main.cpp -o black.out Player.o Deck.o
	
main:
	$(COMP) $(FLAGS) main.cpp -o black.out	
	
player:
	$(COMP) $(FLAGS) -c Player.cpp
	
deck:
	$(COMP) $(FLAGS) -c Deck.cpp
	
interface:
	$(COMP) $(FLAGS) -c Interface.cpp
	
remove:
	rm -fv Player.o Deck.o black.out
	
run:
	./black.out rules.txt
	