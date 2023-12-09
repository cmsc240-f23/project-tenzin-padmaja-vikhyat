#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include <string>
#include "Drink.h"
#include "Consumable.h"

using namespace std;  
using namespace crow;  

TEST_CASE("Testing Drink Class")
{
    // Testing Drink constructor
    SUBCASE("Testing the Drink Constructor") 
    {
        // Create a new Drink class from json.
        Drink testDrink(json::load(R"({"id":"2", "name":"Milk", "cost":10.0, "catConsumable":true, "qty_ml":155})"));
        
        // Check that the constructor properly loaded the values.
        CHECK(testDrink.getId() == "2");
        CHECK(testDrink.getName() == "Milk");
        CHECK(testDrink.getCost() == 10.0 );
        CHECK (testDrink.getCatConsumable() == true );
        CHECK (testDrink.getQtyMl() == 155 );   

    }

    // Testing convertToJson method
    SUBCASE("Testing the convertToJson Method") 
    {
        // Create a new Drink class from json.
        Drink testDrink(json::load(R"({"id":"2", "name":"Milk", "cost":10.0, "catConsumable":true, "qty_ml":155})"));


        // Convert the Drink class to json using the convertToJson method.
        json::wvalue jsonOutput = testDrink.convertToJson();

        // Convert back to a json read value for testing.
        json::rvalue jsonReadValue = json::load(jsonOutput.dump());

        // Check the values.
        CHECK(jsonReadValue["id"].s() == "2");
        CHECK(jsonReadValue["name"].s() == "Milk");
        CHECK (jsonReadValue["cost"].d() == 10.0);
        CHECK (jsonReadValue["catConsumable"].b() == true);
        CHECK (jsonReadValue["qty_ml"].i() == 155);
    
    }

    // Testing updateFromJson method
    SUBCASE("Testing updateFromJson Method") 
    {
        // Create a new Drink class from json.
        Drink testDrink(json::load(R"({"id":"2", "name":"Milk", "cost":10.0, "catConsumable":true, "qty_ml":155})"));

        // Create the update json.
        json::rvalue updateJson = json::load(R"({"id":"2", "name":"Hot Chocolate with Marshmellow", "cost":10.0, "catConsumable":false, "qty_ml":155})");

        // Update the Drink with the updateFromJson method. 
        testDrink.updateFromJson(updateJson);

        // Check the updated values.
        CHECK(testDrink.getId() == "2");
        CHECK(testDrink.getName() == "Hot Chocolate with Marshmellow");
        CHECK(testDrink.getCost() == 10.0 );
        CHECK (testDrink.getCatConsumable() == false );
        CHECK (testDrink.getQtyMl() == 155 ); 
    }

}