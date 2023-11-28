#include <iostream>
#include <string>
#include "Food.h"
using namespace std;

Food::Food(string name, int id, int cost, bool catFood);

int Food::getId()
{
    return id;
}
bool Food::catEdible()
{
    return catFood;
}
void convertToJson()
{
    
}
void updateFromJson()
{
    
}