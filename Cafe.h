#ifndef CAFE_H
#define CAFE_H

#include <crow.h>
#include <iostream>
#include <string>

#include <vector>
#include "Cat.h"
#include "Customer.h"

// #include "Food.h"
// #include "Drink.h"
// #include "CatProduct.h"

class Cafe
{
    public:
        // Constructors
        Cafe() {}
        Cafe(crow::json::rvalue readValueJson);
        
        // getters
        std::string getId() const { return id; }

        // setters
        void setId(std::string idParam) { id = idParam; }

        //
        void donate(float amount) {totalDonation += amount;}

        //convert to JSON
        crow::json::wvalue convertToJson();

        //Update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        std::string id;
        std::string name;
        std::string address;
        float totalDonation = 0;
        std::vector<Cat> cats;
        std::vector<Customer> customers;
        // std::vector<Food> foods;
        // std::vector<Drink> drinks;
        // std::vector<CatProduct> products;
};

#endif
