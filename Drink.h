#include <iostream>
#include <string>
using namespace std;

#ifndef DRINK_H
#define DRINK_H

class Drink : public Consumable
{
    public:
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