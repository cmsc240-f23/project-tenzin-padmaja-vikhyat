#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
#include <string>
using namespace std;

class Consumable
{
    public:
        //constructors
        Consumable() {}
        Consumable(crow::json::rvalue readValueJson);

        //getters
        string getId()const { return id; }
        string getName()const { return name; }
        float getCost() const { return cost; }

        //setters
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setCost(std::float costParam) { cost = costParam; }        

        //convert to JSON
        virtual crow::json::wvalue convertToJson();

        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        

    private:
        string id;
        string name;
        int cost;
};
#endif