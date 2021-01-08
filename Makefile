CFLAGS=-ggdb3 -Wall -Werror -pedantic -std=gnu99

deck: cards.cpp deck.cpp
	g++ -o deck -ggdb3 deck.cpp cards.cpp