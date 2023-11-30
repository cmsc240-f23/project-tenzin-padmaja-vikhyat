#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef FOOD_H
#define FOOD_H

class Food : public Consumable{
    public:
        Food(std::string name, int id, int cost, bool catFriendly);
        int getId();
        bool catEdible();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        std::string name;
        int cost;
        bool catFood;

};
#endif