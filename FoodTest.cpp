#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Food.h"
#include "Consumable.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Food Class")
{
    // Testing Food constructor
    SUBCASE("Testing the Food Constructor") 
    {
        // Create a new Food class from json.
        Food testFood(json::load(R"({"id":"1","name":"Salmon bites", "cost":12.50,"catConsumable":true, "qty_g":300})"));
        
        // Check that the constructor properly loaded the values.
        CHECK(testFood.getId() == "1");
        CHECK(testFood.getName() == "Salmon bites");
        CHECK(testFood.getCost() == 12.50 );
        CHECK (testFood.getCatConsumable() == true);
        CHECK (testFood.getQtyG() == 300 );   

    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Food class from json.
        Food testFood(json::load(R"({"id":"1","name":"Salmon bites", "cost":12.50,"catConsumable":true, "qty_g":300})"));


        // Convert the Food class to json using the convertToJson method.
        json::wvalue jsonOutput = testFood.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "1");
        CHECK(jsonReadValue["name"].s() == "Salmon bites");
        CHECK (jsonReadValue["cost"].d() == 12.50);
        CHECK (jsonReadValue["catConsumable"].b() == true);
        CHECK (jsonReadValue["qty_g"].i() == 300);
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Food class from json.
        Food testFood(json::load(R"({"id":"1","name":"Salmon bites", "cost":12.50,"catConsumable":true, "qty_g":300})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"12","name":"Egg Rolls", "cost":5.50,"catConsumable":false, "qty_g":300})");

        // Update the Food with the updateFromJson method. 
        testFood.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testFood.getId() == "12");
        CHECK(testFood.getName() == "Egg Rolls");
        CHECK(testFood.getCost() == 5.50);
        CHECK (testFood.getCatConsumable() == false);
        CHECK (testFood.getQtyG() == 300 );   
    }

}