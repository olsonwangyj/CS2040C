#include "food.h"
#include <iostream>
using namespace std;

Food Food:: operator+(const Food& rhs) const
{
    // modify this function
    std::string new_name;
    new_name += m_name;
    new_name += " ";
    new_name += rhs.name();
    float new_calories = m_calories + rhs.calories();
    return Food(new_name, new_calories);
}


bool Food:: operator<(const Food& rhs) const
{
    return true;
}

bool Food:: operator==(const Food& rhs) const
{
    return true;
}
