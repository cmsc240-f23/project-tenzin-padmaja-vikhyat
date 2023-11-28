#include <iostream>
#include <string>
using namespace std;

#ifndef FOOD_H
#define FOOD_H

class Food
{
    public:
        Food(string name, int id, int cost, bool catFood);
        int getId();
        bool catEdible();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        string name;
        int cost;
        bool catFood;

};
#endif