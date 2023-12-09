#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
#include <string>
#include <crow.h>

class Consumable
{
    public:
        // Constructors
        Consumable() {}
        Consumable(crow::json::rvalue readValueJson);

        // Getters
        std::string getId()const { return id; }
        std::string getName()const { return name; }
        double getCost() const { return cost; }
        bool getCatConsumable() const { return catConsumable; }

        // Setters
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setCost(double costParam) { cost = costParam; }        
        void setCatConsumable(int catConsumableParam) { catConsumable = catConsumableParam; }

        // Convert to JSON
        virtual crow::json::wvalue convertToJson();

        // Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        std::string id;
        std::string name;
        double cost;
        bool catConsumable;
};

#endif