#include <iostream>
#include <string>
#include <vector>
#include <crow.h>
#include "Cat.h"
#include "Customer.h"
#include "CatProduct.h"
#include "Food.h"
#include "Drink.h"

using namespace std;

#ifndef CAFE_H
#define CAFE_H

class Cafe
{
    public:
        Cafe(crow::json::rvalue readValueJson);
        Cafe() {}
        string getId() const { return id; }
        void setId(std::string idParam) { id = idParam; }
        void donate(float amount) {totalDonation += amount;}
        virtual crow::json::wvalue convertToJson();
        virtual void updateFromJson(crow::json::rvalue readValueJson);
        

    private:
        string id;
        string name;
        string address;
        float totalDonation = 0;
        vector<Customer> customers;
        vector<Food> foods;
        vector<Drink> drinks;
        vector<Cat> cats;
        vector<CatProduct> products;


};
#endif
