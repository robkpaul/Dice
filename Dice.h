#ifndef Dice_H
#define Dice_H
#include <vector>

using std::vector;

class Dice
{
  public:
   Dice();
   Dice(unsigned int);
   int roll();
   vector <int> get_distribution();

  private:
   vector <int> roll_counter;
   const static int FACES = 6;
};

#endif
