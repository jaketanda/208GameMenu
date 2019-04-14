/**************************************************************
*  Ultimate Game Menu
*  Version: 3.1
*
*  Jake Tanda
*  CSCI208
**************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "deck.h"
#include "monte.h"
#include "marble.h"
#include "hand.h"
#include "tool.h"
#include "crazyHand.h"
#include "discardPile.h"

using namespace std;

// Function Prototypes
void showMenu();  // menu
void invalidInputReset();  // resets console after invalid input

// GAMES
void doWar(); // War game
void doMonte(); // Monte game
void doBlackjack(); // Blackjack game
void doRockPaperScissors(); // Rock paper scissors game.
void doCrazy8(); // Crazy 8 game.

// Monte functions
void monteCards(); // Card version of the monte game
void monteMarbles(); // Marble version of the monte game

// BlackJack function
void bjTurn(Hand *cards, Deck *theDeck); // Deals a card to the hand

//*****************************************************
// Start of main routine
//*****************************************************
int main()
{

	int choice=0; // init to ensure while executes once
	srand(time(0)); // seeds the randomizer

	while (choice!=99)
	{
    	showMenu();
    	cin >> choice;
    	if (cin.fail())  // Input validation error
    	{
			choice = 0; // reset choice to indicate invalid choice
			invalidInputReset(); // reset cin to valid state
	    }
    	switch (choice)
		{
			case 1 : // Play War
				doWar();
           		break;
			case 2 : // Play Monte
				doMonte();
				break;
			case 3 : // Play Blackjack
				doBlackjack();
				break;
			case 4 : // Play Blackjack
				doRockPaperScissors();
				break;
			case 5 : // Play Crazy 8s
				doCrazy8();
				break;
        	case 99 :  // end game
            	cout << "\nThanks for playing " << endl << endl;
            	break;
        	default :  // not a valid choice
				cout << "\nError: not a valid selection " << endl;
            	break;
		} // end of switch statement
	} // end of while loop

	return 0;
}

//***************************************
// Function : doWar
// Description: Runs the "War" card game
//*****************************************
void doWar()
{
	cout << "Welcome to War, the video game!\nCopyright 2018 Ubisoft" << endl;
	cout << "Press enter to start the war...";
	cin.ignore();

	Deck warDeck;
	cout << "Deck created...\n";
	warDeck.shuffle(); // initialization and shuffling of the deck.

	int p1_score = 0, p2_score = 0;
	Card p1_card, p2_card;

	cout << "Press enter to go to the next moves..." << endl;

	for (int x = 1; x <= 10; x++)
	{
		cout << "Move " << x << ":" << endl; cin.ignore();
		p1_card = warDeck.deal();
		cout << "Player 1 draws a " << p1_card.toString() << endl; cin.ignore();
		p2_card = warDeck.deal();
		cout << "Player 2 draws a " << p2_card.toString() << endl; cin.ignore();
		if (p1_card > p2_card)
		{
			cout << "Player 1 wins round " << x << "!" << endl;
			p1_score++;
		}
		else
		{
			cout << "Player 2 wins round " << x << "!" << endl;
			p2_score++;
		}
		cin.ignore();
		cout << "Score:\nPlayer 1: " << p1_score << "\nPlayer 2: " << p2_score << endl; cin.ignore();
	}

	if (p1_score > p2_score)
		cout << "Player 1 wins!" << endl;
	else if (p1_score < p2_score)
		cout << "Player 2 wins!" << endl;
	else
		cout << "It's a tie!" << endl;
}


//***************************************
// Function : doMonte
// Description: Runs the "Monte" game
//*****************************************
void doMonte()
{
	int choice = 0;

	cout << "Welcome to Monte, the video game!\nCopyright 1982 EA\n" << endl;

	while (choice != 99)
    {
        cout << "Enter what type of monte you would like to play...\n";
        cout << " 1. Cards\n";
        cout << " 2. Marbles\n";
        cout << "99. Exit Monte\n";
        cin >> choice;

        if (cin.fail())
        {
            choice = 0;
            invalidInputReset();
        }
        switch(choice)
        {
            case 1:
                monteCards();
                break;
            case 2:
                monteMarbles();
                break;
            case 99:
                cout << "\nThanks for choosing Monte as your preferred game\n";
                cout << "Copyright 1982 EA\n\n";
                break;
            default:
                cout << "\nError: not a valid selection " << endl;
                break;
        }
    }
}

//***************************************
// Function : monteCards
// Description: Runs the card version of the monte game
//*****************************************
void monteCards()
{

	Deck randomDeck;
	randomDeck.shuffle();

	int cardChoice = 0;
	Card card1 = randomDeck.deal();
	Card card2 = randomDeck.deal();
	Card card3 = randomDeck.deal();
	Card pickedCard;

	Monte<Card> monteGame(card1, card2, card3);
	monteGame.shuffle();
	cout << "There are three cards on a table in this order: " << endl;
	cout << "1. " << card1.toString() << endl;
	cout << "2. " << card2.toString() << endl;
	cout << "3. " << card3.toString() << endl;
	monteGame.shuffle();

	while (cardChoice > 3 || cardChoice < 1)
	{
		cout << "Enter the new location of the " << card1.toString() << ": ";
		cin >> cardChoice;
		if (cin.fail())
		{
			invalidInputReset();
			cardChoice = 0;
		}
	}
	
	pickedCard = monteGame.pick(cardChoice);
	if (pickedCard.toString() == card1.toString())
		cout << "Correct! You win!\n";
	else
	{
		cout << "Wrong!\n";
		cout << "Final card order: " << endl;
		cout << "1. " << monteGame.pick(1).toString() << endl;
		cout << "2. " << monteGame.pick(2).toString() << endl;
		cout << "3. " << monteGame.pick(3).toString() << endl;
		cout << "\nPress enter to continue...";
		cin.ignore();
		cin.get();
	}
}

//***************************************
// Function : monteMarbles
// Description: Runs the marbles version of the monte game
//*****************************************
void monteMarbles()
{
	int marblechoice;
	Marble marble1("Red");
	Marble marble2("Purple");
	Marble marble3("Green");
	Marble pickedMarble;

	Monte<Marble> monteGame(marble1, marble2, marble3);
	monteGame.shuffle();
	cout << "There are three marbles on a table under a cup in this order: " << endl;
	cout << "1. " << monteGame.pick(1).getColor() << endl;
	cout << "2. " << monteGame.pick(2).getColor() << endl;
	cout << "3. " << monteGame.pick(3).getColor() << endl;
	monteGame.shuffle();

	while (marblechoice > 3 || marblechoice < 1)
	{
		cout << "Enter the new location of the " << marble1.getColor() << " marble: ";
		cin >> marblechoice;
		if (cin.fail())
		{
			invalidInputReset();
			marblechoice = 0;
		}
	}
	
	pickedMarble = monteGame.pick(marblechoice);
	if (pickedMarble.getColor() == marble1.getColor())
		cout << "Correct! You win!\n";
	else
	{
		cout << "Wrong!\n";
		cout << "Final marble order: " << endl;
		cout << "1. " << monteGame.pick(1).getColor() << endl;
		cout << "2. " << monteGame.pick(2).getColor() << endl;
		cout << "3. " << monteGame.pick(3).getColor() << endl;
		cout << "\nPress enter to continue...";
		cin.ignore();
		cin.get();
	}
}

//***************************************
// Function : doBlackJack
// Description: Runs the Blackjack game
//*****************************************
void doBlackjack()
{
	string playerName; // user name

	Deck* bjDeck = new Deck(); // pointer to a deck of cards
	for (int x = 0; x <= 99; x++)
		bjDeck->shuffle();     // shuffles the deck a bunch

	Hand* playerCards = new Hand(); // pointer to the user's hand of cards
	Hand* houseCards = new Hand();  // pointer to the house's hand of cards.

	char continueResponse; // response when the user is prompted if they would
	                       // like to draw another card.

	cout << "Welcome to Ultimate Blackjack! \nEnter your name: ";
	cin >> playerName;
	cout << "\nThe house will start its turn..." << endl << endl;

	for (int x = 0; x < 2; x++) // house's turn
		bjTurn(houseCards, bjDeck); // deals a card to the house 2 times

	cout << "\nThese are the house's cards: ";
	houseCards->displayHand(); // displays the house's hand
	cout << "The house finished their turn with " << houseCards->getHandPoints() << " points." << endl << endl; // displays points of the house

	cout << "It is now " << playerName << "'s turn!\n\n"; 

	for (int x = 0; x < 2; x++) // player's turn
		bjTurn(playerCards, bjDeck); // deals a card to the user 2 times.

	cout << "\nThese are " << playerName << "'s cards: ";
	playerCards->displayHand(); // displays the player's cards
	cout << playerName << " finished their turn with " << playerCards->getHandPoints() << " points." << endl << endl; // displays points of the user

	cout << "Final Stage..." << endl << endl;
	cout << playerName << "'s turn!" << endl;

	if (playerCards->getHandPoints() < 21) // if the user's points are less than 21
	{
		do
		{
			cout << "Would you like to draw another card? (y/n) ";
			cin >> continueResponse;

			if ((continueResponse == 'y' || continueResponse == 'Y')) // if the response is yes
			{
				bjTurn(playerCards, bjDeck); //deal another card
				cout << playerName << " now has " << playerCards->getHandPoints() << " points." << endl << endl; // display user's points
			}
			else if (continueResponse == 'N') // if the response is an uppercase N
				continueResponse = 'n'; // make it lowercase to make the while statement work.

		} while (playerCards->getHandPoints() < 21 && continueResponse != 'n'); // loops while the score less than 21 and the response isn't no
	}
	
	if (playerCards->getHandPoints() < 21) //if the game isn't over because the player could have lost.
		cout << "It is the house's turn!" << endl;

	while (houseCards->getHandPoints() < playerCards->getHandPoints() && houseCards->getHandPoints() < 21 && playerCards->getHandPoints() < 21)
	//while (the house points are less than the users) AND (the house points are less than 21) AND (the user points are less than 21) 
	// house < user < 21 
	{
		bjTurn(houseCards, bjDeck); // Deal another card to the house
		cout << "The house now has " << houseCards->getHandPoints() << " points." << endl << endl; // display house points
	}

	cout << "The game is now over!" << endl;

	cout << "\nCards: \n" <<
			playerName << ": "; playerCards->displayHand(); //Display player cards
	cout << "House: "; houseCards->displayHand(); // display house cards

	cout << "\nScores: \n" <<
			playerName << ": " << playerCards->getHandPoints() << endl << // display player points
			"House: " << houseCards->getHandPoints() << endl << endl; // display house points

	if (((houseCards->getHandPoints() > playerCards->getHandPoints()) && houseCards->getHandPoints() <= 21) || playerCards->getHandPoints() > 21)
	// if (the house points are greater than player points AND the house points are less than or equal to 21) OR the player points are greater than 21
		cout << "The house wins!" << endl; //house wins

	else if (((playerCards->getHandPoints() > houseCards->getHandPoints()) && playerCards->getHandPoints() <= 21) || houseCards->getHandPoints() > 21)
	// if player points are greater than house points AND player points are less than or equal to 21 OR the player points are greater than 21
		cout << playerName << " wins!" << endl; // house wins

	else
		cout << "It's a tie! Unfortunately the technology just isn't there yet for a tiebreaker.." << endl << endl; //tie

	cout << "Thanks for playing! Press enter to continue...";
	cin.ignore(); //ignore input
	cin.get();

	delete bjDeck; // deletes the deck
	delete playerCards;
	delete houseCards; // deletes the two hands
}

//***************************************
// bjTurn (Blackjack turn)
// Description: Runs a player's turn and deals 
//              them a card adding to their 
//              total points.
// Parameters: *cards - a pointer to the hand of cards
//             *theDeck - a pointer to the main blackjack deck
//*****************************************
void bjTurn(Hand *cards, Deck *theDeck)
{
	usleep(1000000); //pauses the program for 1 second

	cout << "A " << theDeck->peek().toString() << " was drawn. " << theDeck->peek().getCardValue() << " points will be added." << endl; 
	//displays the card and its point value

	cards->addHandPoints(theDeck->peek().getCardValue());
	// adds the point value to the total points

	cards->push(theDeck->deal());
	//pushes the card into the hand
}

void doRockPaperScissors()
{
	Tool* playerTool;
	Tool* npcTool;
	int choice, playerScore = 0, cpuScore = 0;
	bool validChoice = false;

	
	
	do // game loop to make it best of three
	{
		cout << "Welcome to Rock Paper Scissors!" << endl;
		cout << "Enter your choice: " << endl;
		cout << "1   Rock" << endl;
		cout << "2   Paper" << endl;
		cout << "3   Scissors" << endl;

		do // loop for input
		{
			cout << ": ";
			cin >> choice;

			if (cin.fail())
			{
				choice = 0;
				invalidInputReset();
			}

			switch (choice)
			{
			case 1:
				playerTool = new Rock;
				validChoice = true;
				break;
			case 2:
				playerTool = new Paper;
				validChoice = true;
				break;
			case 3:
				playerTool = new Scissors;
				validChoice = true;
				break;
			}
		} while (!validChoice);

		choice = rand() % 3 + 1;
		switch (choice)
		{
		case 1:
			npcTool = new Rock;
			break;
		case 2:
			npcTool = new Paper;
			break;
		case 3:
			npcTool = new Scissors;
			break;
		}

		cout << "Player tool: " << playerTool->getType() << endl;
		cout << "Computer tool: " << npcTool->getType() << endl;

		switch (playerTool->fight(npcTool))
		{
		case 0:
			cout << "It's a tie!" << endl;
			break;
		case 1:
			cout << "Player wins!" << endl;
			playerScore++;
			break;
		case 2:
			cout << "Computer wins!" << endl;
			cpuScore++;
			break;
		}
		cout << endl;

		delete npcTool;
		delete playerTool;

		cout << "Player score: " << playerScore << endl;
		cout << "Computer score: " << cpuScore << endl;
	} while (playerScore < 2 && cpuScore < 2);

	cout << endl;
	if (playerScore == 2)
		cout << "Player wins!" << endl;
	else
		cout << "Computer wins!" << endl;

	cout << "Press enter to continue..." << endl;
	cin.ignore(); //ignore input
	cin.get();

	
}

void doCrazy8()
{
	cSuit gameSuit;
	Deck* crazyDeck = new Deck;
	DiscardPile pile;
	Card chosenCard;
	int choice;
	bool valid;
	bool finishedTurn;

	for (int x = 0; x <= 99; x++)
		crazyDeck->shuffle();

	CrazyHand pHand, cHand;
	pHand.deal7(crazyDeck);
	cHand.deal7(crazyDeck);
	pile.pushPile(crazyDeck->pop());

	cout << "Welcome to Crazy 8s!";
	
	do // game loop
	{
		do //Player loop
		{
			finishedTurn = false;

			cout << "It is your turn." << endl;
			cout << "The top card is a " << pile.peek().toString() << endl;
			cout << "Here are your cards: " << endl;
			pHand.printList();
			cout << "99. Draw a card" << endl; // displays the choices for the user.

			cout << "Select which card you would like to place down: ";
			do // card choice loop
			{
				cin >> choice;
				if (cin.fail())  // Input validation error
				{
					choice = -1; // reset choice to indicate invalid choice
					invalidInputReset(); // reset cin to valid state
				}
				if (choice < pHand.getSize() && choice >= 0) // if the choice is valid
					if (pile.isValidCard(choice, pHand))// if the choice is valid
						valid = true;
					else
					{
						valid = false;
						cout << "Not a valid choice" << endl;
					}
				else if (choice == 99)
					valid = true;
				else
				{
					valid = false;
					cout << "Not a valid choice" << endl;
				}
			} while (!valid);

			if (choice == 99)
				pHand.pushFront(crazyDeck->deal()); // pushes the card into the hand from the deck (draws a new card for the player)
			else
			{
				pile.pushPile(pHand.popAPos(choice)); // pushes the valid card into the pile.
				if (pile.peek().getRank() == 8)
				{
					do // loops the suit choice
					{
						cout << "What suit would you like to change the game to?" << endl;
						cout << "1. Clubs" << endl;
						cout << "2. Diamonds" << endl;
						cout << "3. Hearts" << endl;
						cout << "4. Spades" << endl;
						cin >> choice;
					} while (choice > 4 || choice < 1);
					pile.setGameSuit(static_cast<cSuit>(choice-1));
				}
				finishedTurn = true;
			}

			if (crazyDeck->isEmpty())
				finishedTurn = true;
		} while (!finishedTurn);

		cout << endl << "It is now the computer's turn..." << endl;

		do // computer loop
		{
			finishedTurn = false;

			if (cHand.checkForSuit(pile.getGameSuit()) != 99)
			{
				chosenCard = cHand.popAPos(cHand.checkForSuit(pile.getGameSuit()));
				pile.pushPile(chosenCard);
				finishedTurn = true;
				cout << "The computer places down a " << chosenCard.toString() << endl;
			}
			else if (cHand.checkFor8() != 99) 
			{
				chosenCard = cHand.popAPos(cHand.checkFor8());
				pile.pushPile(chosenCard);
				choice = rand() % 3;
				pile.setGameSuit(static_cast<cSuit>(choice));
				cout << "The computer places down a " << chosenCard.toString() << endl;
				cout << "The new suit is ";
				switch (choice)
				{
				case 0:
					cout << "Clubs" << endl;
					break;
				case 1:
					cout << "Diamonds" << endl;
					break;
				case 2:
					cout << "Hearts" << endl;
					break;
				case 3:
					cout << "Spades" << endl;
					break;
				}
				finishedTurn = true;
			}
			else if (cHand.checkForRank(pile.peek().getRank()) != 99)
			{
				chosenCard = cHand.popAPos(cHand.checkForRank(pile.peek().getRank()));
				pile.pushPile(chosenCard);
				finishedTurn = true;
				cout << "The computer places down a " << chosenCard.toString() << endl;
			}
			
			else
			{
				cHand.pushFront(crazyDeck->deal());
			}

			if (crazyDeck->isEmpty())
				finishedTurn = true;
		} while (!finishedTurn);
	} while (pHand.getSize() > 0 && cHand.getSize() > 0 && crazyDeck->getLength() > 0);

	if (pHand.isEmpty() && !cHand.isEmpty())
		cout << "Player wins!" << endl;
	else if (cHand.isEmpty() && !pHand.isEmpty())
		cout << "Computer wins!" << endl;
	else
	{
		if (pHand.getPenaltyPoints() > cHand.getPenaltyPoints())
			cout << "Computer wins!" << endl;
		else if (pHand.getPenaltyPoints() < cHand.getPenaltyPoints())
			cout << "Player wins!" << endl;
		else
			cout << "Tie!" << endl;
	}
	
	cout << "Press enter to continue..." << endl;
	cin.ignore(); //ignore input
	cin.get();
}

//***************************************
// Function : showMenu
// Description: This function presents the menu
//    options on the screen.
//*****************************************
void showMenu()
{
    //system("clear");  // clear the screen
    // cout<<endl << endl << endl << endl;
    cout << "                         " << endl;
    cout << "           _~            " << endl;
    cout << "        _~)_)_~          " << endl;
    cout << "       )_))_))_)         " << endl;
    cout << "       _!__!__!__        " << endl;
    cout << "       \\-o-o-o-t/       " << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "****  GAME MENU   ******" << endl << endl;
    cout << " Please type a choice:"<<endl;

    cout << "  1  War"<<endl;
	cout << "  2  Monte" << endl;
	cout << "  3  Blackjack" << endl;
	cout << "  4  Rock Paper Scissors" << endl;
	cout << "  5  Crazy 8s" << endl;
    cout << " 99  Exit the program"<<endl;
}

//***************************************
// Function : invalidInputReset
// Description: This function resets the cin stream object
//      after in invalid input is detected. It clears the error flags
//      and reads any other 'garbage' on the input line past the last '\n'
//*****************************************
void invalidInputReset()
{
	cin.clear(); // clear the error flags
	cin.ignore(); // skip anything else on the line
}
