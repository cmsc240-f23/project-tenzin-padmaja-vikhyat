#ifndef CAT_H
#define CAT_H

#include <crow.h>
#include <iostream>
#include <string>
#include "Cafe.h"


class Cat
{
    public:
        //Constructors
        Cat() {}
        Cat(crow::json::rvalue readValueJson);

        //getters
        std::string getId() const { return id; }
        std::string getName() const { return name; }
        std::string getBreed() const { return breed; }
        int getAge() const { return age; }
        bool getAvailableForAdoption() const { return availableForAdoption; }
        std::string getRescueStory() const { return rescueStory; }


        //set methods
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setBreed(std::string breedParam) { breed = breedParam; }
        void setAge(int ageParam) { age = ageParam; }
        void setAvailableForAdoption(bool availableForAdoptionParam) { availableForAdoption = availableForAdoptionParam; }
        void setRescueStory(std::string rescueStoryParam) { rescueStory = rescueStoryParam; }

        //fucntion for adopting cat - meanign delete that cat instance 
        Cat Adopt();//deleting the cat

        //convert to JSON
        virtual crow::json::wvalue convertToJson();
        
        //Update from JSON
        virtual void updateFromJson(crow::json::rvalue readValueJson);


    private:
        std::string id;
        std::string name;
        std::string breed;
        int age;
        bool availableForAdoption;
        std::string rescueStory;
};
#endif