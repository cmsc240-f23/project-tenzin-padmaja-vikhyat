#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Cat.h"
#include "FileIO.h"
#include "FileIO.cpp"

using namespace std;
using namespace crow;

TEST_CASE("Saving to a file and loading from a file.") 
{
    // // Load a resources to read.
    map<string, Cat> CatsMap;
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":true, "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":false, "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3", "name": "Tashi", "breed": "Himalayan Cat", "dob":"02/15/2023", "availableForAdoption":true, "rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4", "name": "Kiki", "breed": "Domestic Shorthair", "dob":"07/22/2023", "availableForAdoption":false, "rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};

    // Perform the action
    saveToFile<Cat>(CatsMap, "FileIOTest.json");
    map<string, Cat> CatsMapLoaded = loadFromFile<Cat>("FileIOTest.json");

    // // Check the results
    CHECK(CatsMap.size() == CatsMapLoaded.size()); // Ensure saved and loaded map are the same size.
    CHECK(CatsMap.at("1").getId() == CatsMapLoaded.at("1").getId()); // Validate the resource content
    CHECK(CatsMap.at("1").getName() == CatsMapLoaded.at("1").getName()); // Validate the resource content
    CHECK(CatsMap.at("1").getBreed() == CatsMapLoaded.at("1").getBreed()); // Validate the resource content
    CHECK(CatsMap.at("1").getDob() == CatsMapLoaded.at("1").getDob()); // Validate the resource content
    CHECK(CatsMap.at("1").getAvailableForAdoption() == CatsMapLoaded.at("1").getAvailableForAdoption()); // Validate the resource content
    CHECK(CatsMap.at("1").getRescueStory() == CatsMapLoaded.at("1").getRescueStory()); // Validate the resource content

    CHECK(CatsMap.at("2").getId() == CatsMapLoaded.at("2").getId()); // Validate the resource content
    CHECK(CatsMap.at("2").getName() == CatsMapLoaded.at("2").getName()); // Validate the resource content
    CHECK(CatsMap.at("2").getBreed() == CatsMapLoaded.at("2").getBreed()); // Validate the resource content
    CHECK(CatsMap.at("2").getDob() == CatsMapLoaded.at("2").getDob()); // Validate the resource content
    CHECK(CatsMap.at("2").getAvailableForAdoption() == CatsMapLoaded.at("2").getAvailableForAdoption()); // Validate the resource content
    CHECK(CatsMap.at("2").getRescueStory() == CatsMapLoaded.at("2").getRescueStory()); // Validate the resource content

    CHECK(CatsMap.at("3").getId() == CatsMapLoaded.at("3").getId()); // Validate the resource content
    CHECK(CatsMap.at("3").getName() == CatsMapLoaded.at("3").getName()); // Validate the resource content
    CHECK(CatsMap.at("3").getBreed() == CatsMapLoaded.at("3").getBreed()); // Validate the resource content
    CHECK(CatsMap.at("3").getDob() == CatsMapLoaded.at("3").getDob()); // Validate the resource content
    CHECK(CatsMap.at("3").getAvailableForAdoption() == CatsMapLoaded.at("3").getAvailableForAdoption()); // Validate the resource content
    CHECK(CatsMap.at("3").getRescueStory() == CatsMapLoaded.at("3").getRescueStory()); // Validate the resource content
    
    CHECK(CatsMap.at("4").getId() == CatsMapLoaded.at("4").getId()); // Validate the resource content
    CHECK(CatsMap.at("4").getName() == CatsMapLoaded.at("4").getName()); // Validate the resource content
    CHECK(CatsMap.at("4").getBreed() == CatsMapLoaded.at("4").getBreed()); // Validate the resource content
    CHECK(CatsMap.at("4").getDob() == CatsMapLoaded.at("4").getDob()); // Validate the resource content
    CHECK(CatsMap.at("4").getAvailableForAdoption() == CatsMapLoaded.at("4").getAvailableForAdoption()); // Validate the resource content
    CHECK(CatsMap.at("4").getRescueStory() == CatsMapLoaded.at("4").getRescueStory()); // Validate the resource content
}