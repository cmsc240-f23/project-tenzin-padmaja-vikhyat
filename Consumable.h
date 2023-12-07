#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
#include <string>
#include <crow.h>

class Consumable
{
    public:
        //constructors
        Consumable() {}
        Consumable(crow::json::rvalue readValueJson);

        //getters
        std::string getId()const { return id; }
        std::string getName()const { return name; }
        float getCost() const { return cost; }
        bool isCatConsumable() const { return catConsumable; }

        //setters
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setCost(float costParam) { cost = costParam; }        
        void setCatConsumable(int catConsumableParam) { catConsumable = catConsumableParam; }

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        std::string id;
        std::string name;
        int cost;
        bool catConsumable;
};

#endif