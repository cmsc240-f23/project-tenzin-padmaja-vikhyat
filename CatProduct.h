#include <iostream>
#include <string>
#include <crow.h>
using namespace std;

#ifndef CATPRODUCT_H
#define CATPRODUC_H

class CatProduct
{
    public:
        CatProduct() {}
        CatProduct(crow::json::rvalue readValueJson);
        string getId() const { return id; }
        //int getCost() const { return cost; }
        void setId(std::string idParam) { id = idParam; }
        crow::json::wvalue convertToJson();
        void updateFromJson(crow::json::rvalue readValueJson);


    private:
        string id;
        string name;
        int cost;

};
#endif