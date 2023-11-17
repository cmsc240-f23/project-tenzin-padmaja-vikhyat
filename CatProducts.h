#include <iostream>
#include <string>
using namespace std;

#ifndef CATPRODUCT_H
#define CATPRODUC_H

class CatProduct
{
    public:
        CatProduct(int id, string name, int cost);
        int getId();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        string name;
        int cost;

};
#endif