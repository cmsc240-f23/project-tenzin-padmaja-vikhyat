#include <iostream>
#include <string>
#include "Drink.h"
using namespace std;

Drink::Drink(string name, int id, int cost, bool catDrink);

int Drink::getId()
{
    return id;
}
bool Drink::catEdible()
{
    return catDrink;
}
void convertToJson()
{
    
}
void updateFromJson()
{
    
}