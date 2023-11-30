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
    writeJson["age"] = age;
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
    age = readValueJson["age"].i();
    availableForAdoption = readValueJson["availableForAdoption"].b();
    rescueStory = readValueJson["rescueStory"].s();
}

//look at this later...
Cat Cat::Adopt()
{
    return;
}