#ifndef _CRAZYHAND_H
#define _CRAZYHAND_H
#include "card.h"
#include "list.h"
#include "deck.h"

class CrazyHand : public LinkedList<Card>
{
protected:
	int penaltyPoints;
public:
	CrazyHand();
	void deal7(Deck* crazyDeck);
	int checkForSuit(cSuit);
	int checkForRank(int);
	int checkFor8();
	int getPenaltyPoints();
};

//***************************************
// Constructor for Crazy 8 hand class
// Description: sets the penalty points to 0
//*****************************************
CrazyHand::CrazyHand()
{
	penaltyPoints = 0;
}

//***************************************
// deal7
// Description: deals 7 cards from the deck to the hand
//*****************************************
void CrazyHand::deal7(Deck* crazyDeck)
{
	for (int x = 0; x < 7; x++)
		pushFront(crazyDeck->deal());
}

//***************************************
// checkForSuit
// Description: returns the position of the passed suit,
//              used for computer choices.
//*****************************************
int CrazyHand::checkForSuit(cSuit suit)
{
	Node<Card>* current = frontNodePtr;
	int position = 0;

	do
	{
		if (suit == current->getItem().getSuit()) // if the value matches
			return position;
		current = current->getNextPtr();
		position++;
	} while (current != NULL); // while previous is the back node.
	return 99;
}

//***************************************
// checkForRank
// Description: returns the position of the passed rank,
//              used for computer choices.
//*****************************************
int CrazyHand::checkForRank(int rank)
{
	Node<Card>* current = frontNodePtr;
	int position = 0;

	do
	{
		if (rank == current->getItem().getRank()) // if the value matches
			return position;
		current = current->getNextPtr();
		position++;
	} while (current != NULL); // while previous is the back node.
	return 99;
}

//***************************************
// checkFor8
// Description: returns the position of the 8 card,
//              used for computer choices.
//*****************************************
int CrazyHand::checkFor8()
{
	Node<Card>* current = frontNodePtr;
	int position = 0;

	do
	{
		if (current->getItem().getRank() == 8) // if the value matches
			return position;
		current = current->getNextPtr();
		position++;
	} while (current != NULL); // while previous is the back node.
	return 99;
}

//***************************************
// getPenaltyPoints
// Description: gets the penalty points for a hand
//              used for computer choices.
//*****************************************
int CrazyHand::getPenaltyPoints()
{
	Node<Card>* current = frontNodePtr;
	penaltyPoints = 0;

	do
	{
		if (current->getItem().getRank() == 8)
			penaltyPoints += 20;
		else if (current->getItem().getRank() > 10)
			penaltyPoints += 10;
		else
			penaltyPoints += current->getItem().getRank();
	} while (current != NULL); // while previous is the back node.

	return penaltyPoints;
}

#endif
