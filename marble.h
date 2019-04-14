#ifndef _Marble_H
#define _Marble_H

#include <string>
using namespace std;

class Marble
{
private:
  string color;
public:
  Marble();
  Marble(string marbleColor);
  void setColor(string marbleColor);
  string getColor();
};

/********************************************************
* Default marble constructor
* Purpose: Builds a default marble with the color periwinkle
*****************************************************************/
Marble::Marble()
{
	color = "Periwinkle";
}

/********************************************************
* Parametrized marble constructor
* Purpose: Build marble with a specific color.
* Parameters: marbleColor - the color of the marble.
*****************************************************************/
Marble::Marble(string marbleColor)
{
	color = marbleColor;
}


/********************************************************
* SetColor
* Purpose: Set the color of the marble.
* Parameters: marbleColor - string value that
*             sets the color of the marble.
*****************************************************************/
void Marble::setColor(string marbleColor)
{
	color = marbleColor;
}

/********************************************************
* getColor
* Purpose: Returns the color of the marble.
*****************************************************************/
string Marble::getColor()
{
	return color;
}

#endif
