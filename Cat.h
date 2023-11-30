#ifndef CAT_H
#define CAT_H

#include <crow.h>
#include <iostream>
#include <string>

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
        std::string getDob() const { return dob; }
        bool getAvailableForAdoption() const { return availableForAdoption; }
        std::string getRescueStory() const { return rescueStory; }


        //set methods
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setBreed(std::string breedParam) { breed = breedParam; }
        void setDob(std::string dobParam) { dob = dobParam; }
        void setAvailableForAdoption(bool availableForAdoptionParam) { availableForAdoption = availableForAdoptionParam; }
        void setRescueStory(std::string rescueStoryParam) { rescueStory = rescueStoryParam; }

        //fucntion for adopting cat - meanign delete that cat instance 
        void Adopt();//deleting the cat

        //convert to JSON
        crow::json::wvalue convertToJson();
        
        //Update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);

    private:
        std::string id;
        std::string name;
        std::string breed;
        std::string dob;
        bool availableForAdoption;
        std::string rescueStory;
};
#endif