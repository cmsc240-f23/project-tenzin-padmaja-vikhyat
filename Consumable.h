#include <iostream>
#include <string>
using namespace std;

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Consumable
{
    public:
    Record() {}
        Drink(string name, int id, int cost, bool catDrink);
        int getId();
        bool catEdible();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        string name;
        int cost;
        bool catDrink;

};
#endif