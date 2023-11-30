#include <iostream>
#include <string>
using namespace std;

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

class Consumable
{
    public:
        Consumable() {}
        Consumable(crow::json::rvalue readValueJson);
        int getId()const { return id; }
        //bool catEdible();

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        


    private:
        string id;
        string name;
        int cost;
        //bool catDrink;

};
#endif