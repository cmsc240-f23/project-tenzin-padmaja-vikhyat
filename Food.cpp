#include <iostream>
#include <string>
#include "Food.h"
using namespace std;

Food::Food(string name, int id, int cost, bool catFriendly);

int Food::getId()
{
    return id;
}
bool Food::catEdible()
{
    return catFriendly;
}
void convertToJson()
{
    
}
void updateFromJson()
{
    
}