# Makefile for Separate Compilation Example

# *****************************************************
# Parameters to control Makefile operation

CXX = g++

# flag -g set for debugging

CXXFLAGS = -Wall -g

# ****************************************************
# Entries to bring the executable up to date

main: menu.o
	$(CXX) $(CXXFLAGS) -o test menu.o 

main.o: card.h deck.h monte.h marble.h hand.h node.h stack.h tool.h discardPile.h crazyHand.h







