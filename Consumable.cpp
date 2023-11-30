#include <iostream>
#include <string>

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Consumable{
    public:
        Consumable() {}
        Consumable(std::string name, int id, int cost, bool catFriendly);
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