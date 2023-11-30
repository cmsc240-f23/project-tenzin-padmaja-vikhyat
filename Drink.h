#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef DRINK_H
#define DRINK_H

class Drink : public Consumable{
    public:
        Drink(std::string name, int id, int cost, bool catDrink);
        int getId();
        bool catEdible();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        std::string name;
        int cost;
        bool catDrink;

};
#endif