#include "Dice.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//class constructor that seeds the random number generator
Dice::Dice()
{
    srand(time(NULL));
    roll_counter.resize(FACES);

    for(int i=0; i<FACES; i++)
      roll_counter[i] = 0;
}

//overloaded constructor
Dice::Dice(unsigned int num)
{
    if( num == 0 )
    {
        roll_counter.resize(FACES);
    }
    else{
        roll_counter.resize(num);
    }
    for(int i=0; i<FACES; i++)
    {
        roll_counter[i] = 0;
    }

}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int Dice::roll()
{
    int roll = rand() % roll_counter.size();
    roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <double> Dice::get_distribution(){
    vector<double> dist;
    double total_rolls = 0;
    for(vector<int>::iterator itr = roll_counter.begin(); itr != roll_counter.end(); itr++){
        total_rolls += *itr;
    }
    for(int i = 0; i < roll_counter.size(); i++) {
        dist.push_back(roll_counter[i] / total_rolls);
    }
    return dist;
}
