#ifndef CAFE_H
#define CAFE_H

#include <crow.h>
#include <iostream>
#include <string>

#include <vector>
#include "Cat.h"

// #include "Food.h"
// #include "Drink.h"

class Cafe
{
    public:
        // Constructors
        Cafe() {}
        Cafe(crow::json::rvalue readValueJson);
        
        // getters
        std::string getId() const { return id; }
        std::string getName() const { return name; }
        std::string getAddress() const { return address; }


        // setters
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setAddress(std::string addressParam) { name = addressParam; }

        //convert to JSON
        crow::json::wvalue convertToJson();

        //Update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        std::string id;
        std::string name;
        std::string address;
        //std::vector<Cat> cats;
        //std::vector<Customer> customers;
        // std::vector<Food> foods;
        // std::vector<Drink> drinks;
};

#endif
