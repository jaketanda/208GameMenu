#ifndef _CARD_H
#define _CARD_H
#include <string>
using namespace std;

enum cSuit {Clubs, Diamonds, Hearts, Spades};

class Card
{
        private:
                cSuit Suit;
                int Rank;
				int pointWorth;
        public:
                Card();
                Card(int cardRank, cSuit cardSuit);
                void setRank(int cardRank);
                void setSuit(cSuit cardSuit);
				void setPointValue(int val);
                int getRank();
				int getCardValue();
                cSuit getSuit();
				string toString();
};

//bool operator<(Card a, Card b);
bool operator>(Card a, Card b); // overloaded > operator
//ostream& operator<< (ostream & os, Card a);

/********************************************************
* Default card constructor
* Purpose: Build default card with suit
*          clubs and a rank of joker.
*****************************************************************/
Card::Card()
{
	Suit = Clubs;
	Rank = 0;
	pointWorth = 0;
}


/********************************************************
* Card constructor
* Purpose: Build a card using the cardRank and cardSuit
* Parameters: cardRank - int value 0-13 that sets the rank of the card.
*             cardSuit - cSuit value that sets the suit of the card.
*****************************************************************/
Card::Card(int cardRank, cSuit cardSuit)
{
	Suit = cardSuit;
	if (cardRank <= 13 && cardRank >= 0)
		Rank = cardRank;
	else
		Rank = 0;

	pointWorth = Rank; //used to set the card point value for blackjack.
	if (Rank > 10)
		pointWorth = 10;
}

/********************************************************
* SetRank
* Purpose: Set the rank of the card.
* Parameters: cardRank - int value 0-13 that sets the rank of the card.
*****************************************************************/
void Card::setRank(int cardRank)
{
	Rank = cardRank;
}

/********************************************************
* SetSuit
* Purpose: Set the suit of the card.
* Parameters: cardSuit - cSuit value that sets the suit of the card.
*****************************************************************/
void Card::setSuit(cSuit cardSuit)
{
	Suit = cardSuit;
}

/********************************************************
* SetPointValue
* Purpose: Set the point value of the card.
* Parameters: val - value that sets the numeric value of the card
*****************************************************************/
void Card::setPointValue(int val)
{
	pointWorth = val;
}

/********************************************************
* getRank
* Purpose: Returns the rank of the card.
*****************************************************************/
int Card::getRank()
{
	return Rank;
}

/********************************************************
* getCardValue
* Purpose: Returns the point value of the card. (for blackjack)
*****************************************************************/
int Card::getCardValue()
{
	return pointWorth;
}


/********************************************************
* getSuit
* Purpose: Returns the Suit of the card.
*****************************************************************/
cSuit Card::getSuit()
{
	return Suit;
}

/********************************************************
* operator>
* Purpose: comparison of cards.
*****************************************************************/
bool operator>(Card card1, Card card2)
{
	if (card1.getRank() > card2.getRank())
		return true;
	else if (card1.getRank() < card2.getRank())
		return false;
	else
	{
		if (card1.getSuit() > card2.getSuit())
			return true;
		else
			return false;
	}
}

/********************************************************
*
* toString
*
* Purpose: Returns the string value of the card.
*
*****************************************************************/
string Card::toString()
{
	string sSuit, sRank, card;
	switch (Rank)
	{
	case 0:
		sRank = "Joker";
		break;
	case 1:
		sRank = "Ace";
		break;
	case 2:
		sRank = "Two";
		break;
	case 3:
		sRank = "Three";
		break;
	case 4:
		sRank = "Four";
		break;
	case 5:
		sRank = "Five";
		break;
	case 6:
		sRank = "Six";
		break;
	case 7:
		sRank = "Seven";
		break;
	case 8:
		sRank = "Eight";
		break;
	case 9:
		sRank = "Nine";
		break;
	case 10:
		sRank = "Ten";
		break;
	case 11:
		sRank = "Jack";
		break;
	case 12:
		sRank = "Queen";
		break;
	case 13:
		sRank = "King";
		break;
	}

	switch (Suit)
	{
	case Spades:
		sSuit = "Spades";
		break;
	case Hearts:
		sSuit = "Hearts";
		break;
	case Diamonds:
		sSuit = "Diamonds";
		break;
	case Clubs:
		sSuit = "Clubs";
		break;
	}

	if (Rank == 0)
		card = sRank; //if a Joker it does not have a suit, so only return the Joker part.
	else
		card = sRank + " of " + sSuit; // ex. 'Ace of Spades'
	return card;
}

#endif