#ifndef _Monte_h
#define _Monte_h
#include <string>

using namespace std;

//template where T is the variable used.
template <class T>
class Monte
{
private:
  T thing[3];
public:
  Monte(T thing1, T thing2, T thing3);
  void setThing1(T thing1);
  void setThing2(T thing2);
  void setThing3(T thing3);
  void shuffle();
  T pick(int choice);
};

//***************************************
// Function : Monte constructor
// Input: 3 T variables
// output: none
// Description: sets the three "thing"s equal to what is set from the main program
//*****************************************
template <class T>
Monte<T>::Monte(T thing1, T thing2, T thing3)
{
  thing[0] = thing1;
  thing[1] = thing2;
  thing[2] = thing3;
}


//***************************************
// Function : setters
// Input: T thing
// output: none
// Description: sets the "thing"s
//*****************************************
template <class T>
void Monte<T>::setThing1(T thing1)
{ thing[0] = thing1; }

template <class T>
void Monte<T>::setThing2(T thing2)
{ thing[1] = thing2; }

template <class T>
void Monte<T>::setThing3(T thing3)
{ thing[2] = thing3; }


//***************************************
// Function : shuffle
// Input: none
// output: none
// Description: shuffles the things
//*****************************************
template <class T>
void Monte<T>::shuffle()
{
  for (int x = 0; x <= 2; x++)
  {
    int r = rand() % 3;

    T temp = thing[x];
    thing[x] = thing[r];
    thing[r] = temp;
  }
}

//***************************************
// Function : pick
// Input: int choice
// output: T variable
// Description: picks a thing from the array of things, and returns that thing.
//*****************************************
template <class T>
T Monte<T>::pick(int choice)
{ return thing[choice-1]; }

#endif
