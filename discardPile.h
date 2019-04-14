#ifndef _DISCARDPILE_H
#define _DISCARDPILE_H
#include "stack.h"
#include "card.h"
#include "crazyHand.h"

class DiscardPile : public Stack<Card>
{
protected:
	cSuit gameSuit;
public:
	DiscardPile();
	cSuit getGameSuit();
	void setGameSuit(cSuit changeSuit);
	bool isValidCard(int choice, CrazyHand hand);
	void pushPile(Card);
};

//***************************************
// DiscardPile constructor
// Description: sets gamesuit to default at spades.
//*****************************************
DiscardPile::DiscardPile()
{
	gameSuit = Spades;
}

//***************************************
// getGameSuit
// Description: returns the suit of the game currently
//*****************************************
cSuit DiscardPile::getGameSuit()
{
	return gameSuit;
}

//***************************************
// setGameSuit
// Description: sets the gamesuit to the passed suit
//*****************************************
void DiscardPile::setGameSuit(cSuit changeSuit)
{
	gameSuit = changeSuit;
}

//***************************************
// isValidCard
// Description: checks if the choice is a card in the deck
//*****************************************
bool DiscardPile::isValidCard(int choice, CrazyHand hand)
{
	Card checkCard = hand.peekAPos(choice);
	if (checkCard.getSuit() == gameSuit)
		return true;
	else if (checkCard.getRank() == peek().getRank())
		return true;
	else if (checkCard.getRank() == 8)
		return true;
	else
		return false;
}

//***************************************
// checkForRank
// Description: pushes a card into the pile.
//*****************************************
void DiscardPile::pushPile(Card pushCard)
{
	//create a new Node
	// this should point to old top
	Node<Card>* newNode = new Node<Card>(pushCard, topPtr);
	topPtr = newNode;
	length++;

	gameSuit = pushCard.getSuit();

	return;

	//top of stack shold point to new node
}

#endif