#ifndef _Hand_H
#define _Hand_H

#include "card.h"
#include "node.h"
#include "stack.h"
#include <time.h>
#include <math.h>
#include <cstdlib>
using namespace std;

class Hand : public Stack<Card>
{
protected:
	int points;      //total points added from cards
public:
	Hand();
	~Hand();
	int getHandPoints();
	void addHandPoints(int);
	void displayHand();
};

/********************************************************
* Default hand constructor
* Purpose: Sets points to 0
*****************************************************************/
Hand::Hand()
{
	points = 0;
}

/********************************************************
* Deck deconstructor
* Purpose: Empties the hand of cards before it is deleted
*****************************************************************/
Hand::~Hand()
{
	while (!isEmpty())
		pop();
}

/********************************************************
* getHandPoints
* Purpose: Returns the points of the hand of cards
*****************************************************************/
int Hand::getHandPoints()
{
	return points;
}

/********************************************************
* addHandPoints
* Purpose: adds points to the hand of cards
* Parameters: addedPoints - int amount of points to be added
*****************************************************************/
void Hand::addHandPoints(int addedPoints)
{
	points += addedPoints;
}

/********************************************************
* displayHand
* Purpose: Displays all of the cards
*          in the hand at once in a neat list.
*****************************************************************/
void Hand::displayHand()
{
	Stack<Card> tempHand; //temporary stack
	Card tempCard; // temp card
	int tempLength = length;

	for (int x = 0; x < tempLength; x++)
	{
		tempCard = this->pop(); // takes a card out of the hand and moves it to the temp card
		cout << tempCard.toString();
		if (x == (tempLength - 1))
			cout << "." << endl;
		else
			cout << ", ";             // Ex. "Ace of Spades, King of Hearts." 
		tempHand.push(tempCard);  //pushes the temp card to the temp hand
	}

	for (int x = 0; x < tempLength; x++)
		this->push(tempHand.pop());   //pushes all of the temp hand back to the regular one
}

#endif