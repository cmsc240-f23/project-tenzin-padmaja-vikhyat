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
        Cafe testCafe(json::load(R"({"id":"1", "name" : "Catland Cafe" , "address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})"));

        // Check that the constructor properly loaded the values.
        CHECK(testCafe.getId() == "1");
        CHECK(testCafe.getName() == "Catland Cafe");
        CHECK(testCafe.getAddress() == "565 Cedar Rd., Suite 12 Chesapeake, VA 23322");
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Cafe class from json.
        Cafe testCafe(json::load(R"({"id":"1", "name" : "Catland Cafe" , "address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})"));

        // Convert the Genre class to json using the convertToJson method.
        json::wvalue jsonOutput = testCafe.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Catland Cafe");
        CHECK(jsonReadValue["address"].s() == "565 Cedar Rd., Suite 12 Chesapeake, VA 23322");
    }
        // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Cafe class from json.
        Cafe testCafe(json::load(R"({"id":"1", "name" : "Catland Cafe" , "address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"2", "name" : "Kat Kingdom Cafe" , "address":"214 Juniper Rd., B23, Richmond, VA 23173"})");

        // Update the Genre with the updateFromJson method. 
        testCafe.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testCafe.getId() == "2");
        CHECK(testCafe.getName() == "Kat Kingdom Cafe");
        CHECK(testCafe.getAddress() == "214 Juniper Rd., B23, Richmond, VA 23173");
    }
    

}