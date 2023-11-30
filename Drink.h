#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef FOOD_H
#define FOOD_H

class Food : public Consumable{
    public:
        Food() {}
        Food(crow::json::rvalue readValueJson);
        //int getId()const { return id; }
        //bool catEdible();

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        

    private:
        int qty_ml;
        //bool catFood;

};
#endif