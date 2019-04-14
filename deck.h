#ifndef _Deck_H
#define _Deck_H

#include "card.h"
#include "node.h"
#include "stack.h"
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;

const int DeckIsEmptyException = 1042;
const int DeckIsFullException = 1043;

class Deck : public Stack<Card>
{
public:
  Deck();
  ~Deck();
  Card deal();
  void shuffle();
};

/********************************************************
* Default deck constructor
* Purpose: Build default deck of
*          52 cards
*****************************************************************/
Deck::Deck()
{
	Card tempCard;

	for (int y = 0; y < 4; y++)
	{
		for (int z = 1; z <= 13; z++)
		{
			tempCard.setSuit(static_cast<cSuit>(y)); // sets the suit (0-3)
			tempCard.setRank(z); //sets rank (1-13)
			if (z >= 10)     //below this point is for points in blackjack
				tempCard.setPointValue(10);
			else
				tempCard.setPointValue(z);
			push(tempCard);
		}
	}
}

/********************************************************
* Deck deconstructor
* Purpose: Empties the deck of cards before it is deleted
*****************************************************************/
Deck::~Deck()
{
	while (!isEmpty())
	{
		pop();
	}
}

/********************************************************
* deal
* Purpose: Returns a card after popping it from the stack
*****************************************************************/
Card Deck::deal()
{
	Card cardtemp = pop();
	return cardtemp;
}

/********************************************************
* shuffle
* Purpose: shuffles the stack of cards
*****************************************************************/
void Deck::shuffle()
{
	if (isEmpty()) { throw DeckIsEmptyException; }

	//Get a random # between 1 - 8
	int randnum = (rand() % 8) + 1;
	//Build Stack A, Size 22 + Rand#
	Stack<Card> pileA;
	for (int x = 0; x < 22 + randnum; x++)
		pileA.push(this->pop());

	//Build Stack B w/ rest of cards
	Stack<Card> pileB;
	while (this->isEmpty() == false)
	{
		pileB.push(this->pop());
	};
	//Merge the Stacks
	while ((pileA.isEmpty() == false) || (pileB.isEmpty() == false))
	{
		if (pileA.isEmpty() == false)
		{
			Card aCard = pileA.pop();
			this->push(aCard);
		}
		if (pileB.isEmpty() == false)
		{
			Card bCard = pileB.pop();
			this->push(bCard);
		}
	}
}


#endif
