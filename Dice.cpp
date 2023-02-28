#include "Dice.h"
#include <vector>
#include <cstdlib>
#include <ctime>

//class constructor that seeds the random number generator
Dice::Dice()
{
    srand(time(NULL));
    m_roll_counter.resize(m_FACES);

    for(int i=0; i<m_FACES; i++)
      m_roll_counter[i] = 0;
}

//overloaded constructor
Dice::Dice(unsigned int num)
{
    if( num == 0 )
    {
        m_roll_counter.resize(m_FACES);
    }
    else{
        m_roll_counter.resize(num);
    }
    for(int i=0; i<m_FACES; i++)
    {
        m_roll_counter[i] = 0;
    }

}

//generate a random number between 1-n where n is the counter size
// (inclusive) and return it
int Dice::roll()
{
    int roll = rand() % m_roll_counter.size();
    m_roll_counter[roll]++;
    return roll + 1;
}

// return the count of how many times each face has been rolled, as a vector
// where each face's count is at index face-1 (i.e. Face 1 is at index 0)
vector <double> Dice::get_distribution(){
    vector<double> dist;
    double total_rolls = 0;
    for(vector<int>::iterator itr = m_roll_counter.begin(); itr != m_roll_counter.end(); itr++){
        total_rolls += *itr;
    }
    for(int i = 0; i < m_roll_counter.size(); i++) {
        dist.push_back(m_roll_counter[i] / total_rolls);
    }
    return dist;
}
