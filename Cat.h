#include <iostream>
#include <string>
using namespace std;

#ifndef CAT_H
#define CAT_H

class Cat
{
    public:
        Cat(int id, string name, string breed, int age, bool availableForAdoption);
        int getId();
        string getRescueStory();
        Cat Adopt();
        string getCatInfo();
        void convertToJson();
        void updateFromJson();


    private:
        int id;
        string name;
        string breed;
        int age;
        bool availableForAdoption;

};
#endif