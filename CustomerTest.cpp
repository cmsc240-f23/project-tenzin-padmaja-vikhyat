#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Customer.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Customer Class") 
{
    SUBCASE("Testing the Customer Constructor") 
    {
        // Create a new Consumable class from json.
        Customer testCustomer(json::load(R"({"id":"1","name":"Rohan", "email":"rohan@jmail.com", "numberOfVisits":155,"phoneNumber":"+1 804 123 5648", "isMember":true })"));

        // Check that the constructor properly loaded the values.
        CHECK(testCustomer.getId() == "1");
        CHECK(testCustomer.getName() == "Rohan");
        CHECK(testCustomer.getEmail() == "rohan@jmail.com");
        CHECK(testCustomer.getNumOfVisits() == 155);
        CHECK(testCustomer.getPhoneNum() == "+1 804 123 5648");
        CHECK(testCustomer.getIsMember() == true);
        
    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Cafe class from json.
        Customer testCustomer(json::load(R"({"id":"1","name":"Rohan", "email":"rohan@jmail.com", "numberOfVisits":155,"phoneNumber":"+1 804 123 5648", "isMember":true })"));

        // Convert the Genre class to json using the convertToJson method.
        json::wvalue jsonOutput = testCustomer.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Rohan");
        CHECK(jsonReadValue["email"].s() == "rohan@jmail.com");
        CHECK(jsonReadValue["numberOfVisits"].i() == 155);
        CHECK(jsonReadValue["phoneNumber"].s() == "+1 804 123 5648");
        CHECK(jsonReadValue["isMember"].b() == true);
        
        
    }
        // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Customer class from json.
        Customer testCustomer(json::load(R"({"id":"1","name":"Rohan", "email":"rohan@jmail.com", "numberOfVisits":155,"phoneNumber":"+1 804 123 5648", "isMember":true })"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"2", "name":"Vishal", "email":"vishal@jmail.com", "numberOfVisits":12, "phoneNumber":"+1 804 123 5667", "isMember":false})");

        // Update the Customer with the updateFromJson method. 
        testCustomer.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testCustomer.getId() == "2");
        CHECK(testCustomer.getName() == "Vishal");
        CHECK(testCustomer.getEmail() == "vishal@jmail.com");
        CHECK(testCustomer.getNumOfVisits() == 12);
        CHECK(testCustomer.getPhoneNum() == "+1 804 123 5667");
        CHECK(testCustomer.getIsMember() == false);
    }
}