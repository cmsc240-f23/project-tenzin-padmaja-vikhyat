#include <iostream>
#include <string>
#include "Consumable.h"

#ifndef DRINK_H
#define DRINK_H

class Drink : public Consumable{
    public:
        Drink() {}
        Drink(crow::json::rvalue readValueJson);

        //getter
        int getQtyMl()const { return qty_ml; }

        //setter
        void setQtyMl(int qty_mlParam) {qty_ml = qty_mlParam;}

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        //quanitity in ml
        int qty_ml;
     
};
#endif