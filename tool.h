#include <string>
#include <iostream>
using namespace std;

class Tool
{
protected:
	string type;
public:

	//***************************************
	// Function : Tool Constructor
	// Description: sets the type to undefined
	//*****************************************
	Tool()
	{ type = "undefined"; }

	//***************************************
	// Function : virtual fight function
	// Description: pure fight function
	//*****************************************
	virtual int fight(Tool* opponent) = 0;

	//***************************************
	// Function : getType
	// Description: returns the type of tool
	//*****************************************
	string getType()
	{ return type; }

	//***************************************
	// Function : Tool destructor
	//*****************************************
	virtual ~Tool()
	{
		type = "";
	}
};

class Rock : public Tool
{
public:
	//***************************************
	// Function : Rock Constructor
	// Description: sets the type to rock
	//*****************************************
	Rock()
	{ type = "Rock"; }

	//***************************************
	// Function : fight function
	// Description: fights the player with whatever is passed.
	//*****************************************
	int fight(Tool* opponent)
	{
		if (opponent->getType() == "Rock")
			return 0;
		else if (opponent->getType() == "Scissors")
			return 1;
		return 2;
	}

	//***************************************
	// Function : Rock destructor
	//*****************************************
	~Rock()
	{
		type = "";
	}
};

class Paper : public Tool
{
public:
	//***************************************
	// Function : Paper Constructor
	// Description: sets the type to paper
	//*****************************************
	Paper()
	{ type = "Paper"; }

	//***************************************
	// Function : fight function
	// Description: fights the player with whatever is passed.
	//*****************************************
	int fight(Tool* opponent)
	{
		if (opponent->getType() == "Paper")
			return 0;
		else if (opponent->getType() == "Rock")
			return 1;
		return 2;
	}

	//***************************************
	// Function : Paper destructor
	//*****************************************
	~Paper()
	{
		type = "";
	}
};

class Scissors : public Tool
{
public:
	//***************************************
	// Function : Scissors Constructor
	// Description: sets the type to scissors
	//*****************************************
	Scissors()
	{ type = "Scissors"; }

	//***************************************
	// Function : fight function
	// Description: fights the player with whatever is passed.
	//*****************************************
	int fight(Tool* opponent)
	{
		if (opponent->getType() == "Scissors")
			return 0;
		else if (opponent->getType() == "Paper")
			return 1;
		return 2;
	}

	//***************************************
	// Function : Scissors destructor
	//*****************************************
	~Scissors()
	{
		type = "";
	}
};