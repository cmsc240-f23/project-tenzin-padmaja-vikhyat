#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Cafe.h"

using namespace std;  
using namespace crow;  



TEST_CASE("Testing Cafe Class") 
{
    SUBCASE("Testing the Cafe Constructor") 
    {
        // Create a new Cafe class from json.
        Cafe testCafe(json::load(R"({"genre":"Rock","id":"1"})"));

        // Check that the constructor properly loaded the values.
        CHECK(testCafe.getId() == "1");
        //CHECK(testCafe.getGenre() == "Rock");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Cafe class from json.
        Cafe testCafe(json::load(R"({"genre":"Rock","id":"1"})"));

        // Convert the Genre class to json using the convertToJson method.
        json::wvalue jsonOutput = testCafe.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        //CHECK(jsonReadValue["genre"].s() == "Rock");
    }
        // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Cafe class from json.
        Cafe testGenre(json::load(R"({"genre":"Rock","id":"1"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"genre":"Jazz","id":"2"})");

        // Update the Genre with the updateFromJson method. 
        testCafe.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testCafe.getId() == "2");
        //CHECK(testGenre.getGenre() == "Jazz");
    }
    

}