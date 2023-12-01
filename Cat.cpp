#include "Cat.h"

using namespace std;
using namespace crow;

Cat::Cat(json::rvalue readValueJson){
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Cat::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = id;
    writeJson["name"] = name;
    writeJson["breed"] = breed;
    writeJson["dob"] = dob;
    writeJson["availableForAdoption"] = availableForAdoption;
    writeJson["rescueStory"] = rescueStory;
    return writeJson;
}

// Update from JSON
void Cat::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    name = readValueJson["name"].s();
    breed = readValueJson["breed"].s();
    dob = readValueJson["dob"].s();
    availableForAdoption = readValueJson["availableForAdoption"].b();
    rescueStory = readValueJson["rescueStory"].s();
}
