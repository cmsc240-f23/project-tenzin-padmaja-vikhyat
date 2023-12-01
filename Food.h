#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef FOOD_H
#define FOOD_H

class Food : public Consumable{
    public:
        Food() {}
        Food(crow::json::rvalue readValueJson);

        //getter
        int getQtyG()const { return qty_g; }

        //setter
        void setQtyG(int qty_gParam) {qty_g = qty_gParam;}

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        //quantity in grams
        int qty_g;
};
#endif