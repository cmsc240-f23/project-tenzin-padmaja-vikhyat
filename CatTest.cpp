#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Cat.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Cat Class")
{
    // Testing Cat constructor
    SUBCASE("Testing the Cat Constructor") 
    {
        // Create a new Cat class from json.
        Cat testCat(json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})"));
        
        // Check that the constructor properly loaded the values.
        CHECK(testCat.getId() == "1");
        CHECK(testCat.getName() == "Meowy");
        CHECK(testCat.getBreed() == "Turkish Angora" );
        CHECK (testCat.getDob() == "12/29/2022" );
        CHECK (testCat.getAvailableForAdoption() == true );
        CHECK (testCat.getRescueStory() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her." );
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Cat class from json.
        Cat testCat(json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})"));

        // Convert the Cat class to json using the convertToJson method.
        json::wvalue jsonOutput = testCat.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Meowy");
        CHECK (jsonReadValue["breed"].s() == "");
        CHECK (jsonReadValue["dob"].s() == "");
        CHECK (jsonReadValue["availableForAdoption"].b() == true);
        CHECK (jsonReadValue["rescueStory"].s() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her.");
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Cat class from json.
        Cat testCat(json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":"false", "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})");

        // Update the Cat with the updateFromJson method. 
        testCat.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testCat.getId() == "2");
        CHECK(testCat.getName() == "Luna");
        CHECK(testCat.getBreed() == "Burmese Cat" );
        CHECK (testCat.getDob() == "05/09/2022" );
        CHECK (testCat.getAvailableForAdoption() == false );
        CHECK (testCat.getRescueStory() == "This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!" );
    }

}