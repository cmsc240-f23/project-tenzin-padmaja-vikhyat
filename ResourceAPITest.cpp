#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Cat.h"
#include "Cafe.h"
#include "ResourceAPI.h"
#include "Customer.h"
#include "Consumable.h"
#include "Food.h"
#include "Drink.h"

#include <map>
#include <string>

using namespace std;
using namespace crow;

map<string, Cat> CatsMap;
map<string, Cafe> CafeMap; 
map<string, Customer> CustomersMap;
map<string, Food> FoodsMap;
map<string, Drink> DrinksMap;

// bool jsonEqual(string responseBody, string expected){
//     string strJson = expected; // need escape the quotes
//     Json::Value root;   
//     Json::Reader reader;
//     bool parsingSuccessful = reader.parse(strJson.c_str(), root);     //parse process
//     if (!parsingSuccessful)
//     {
//         cout  << "Failed to parse" << reader.getFormattedErrorMessages() << endl;
//         return 0;
//     }
//     cout << root.get("mykey", "A Default Value if not exists" ).asString() << endl;


//     return false;
// }

//-----------------------------------------------------------
//Customers

//Endpoint cases for Customers
TEST_CASE("Creating a new Customer resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Customer>::resourceMap.clear();
    CustomersMap.clear();

    // Setup request object
    request req;
    req.body = R"({"isMember":true,"phoneNumber":"+1 804 123 5648","numberOfVisits":155,"email":"rohan@jmail.com","id":"1","name":"Rohan"})"; 

    // Perform the action
    response res = ResourceAPI<Customer>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Customer>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getName() == "Rohan");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getEmail() == "rohan@jmail.com");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getNumOfVisits() == 155);
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getPhoneNum() == "+1 804 123 5648");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getIsMember() == true);
}

TEST_CASE("Reading a Customer resource") 
{
    ResourceAPI<Customer>::resourceMap.clear();
    CustomersMap.clear();
    
    // Load a resource to read.
    CustomersMap["1"] = Customer{json::load(R"({"id":"1","name":"Rohan","email":"rohan@jmail.com","numberOfVisits":155,"phoneNumber":"+1 804 123 5648","isMember":true})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Customer>::resourceMap = CustomersMap;

    // Perform the action
    response res = ResourceAPI<Customer>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(ResourceAPI<Customer>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
    CHECK(res.body == CustomersMap["1"].convertToJson().dump()); // Validate the reponse body
}

TEST_CASE("Reading all Customer resources") 
{
    // Load resources to read.
    CustomersMap["1"] = Customer{json::load(R"({"id":"1","name":"Rohan","email":"rohan@jmail.com","numberOfVisits":155,"phoneNumber":"+1 804 123 5648","isMember":true})")};
    CustomersMap["2"] = Customer{json::load(R"({"id":"2","name":"Vishal","email":"Vishal@jmail.com","numberOfVisits":5,"phoneNumber":"+1 800 354 6783","isMember":false})")};
    CustomersMap["3"] = Customer{json::load(R"({"id":"3","name":"Shekhar","email":"Shekhar@jmail.com","numberOfVisits":300,"phoneNumber":"+1 801 643 7265","isMember":true})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Customer>::resourceMap = CustomersMap;

    // Setup request object
   //request req;

    // Perform the action
    //response res = ResourceAPI<Customer>::readAllResources(req);
    response res = ResourceAPI<Customer>::readAllResources();


    // Create the expected reponse body
    //string expectedResponseBody = R"([{"id":"1","name":"Rohan","email":"rohan@jmail.com","numberOfVisits":155,"phoneNumber":"+1 804 123 5648","isMember":true},{"id":"2","name":"Vishal","email":"Vishal@jmail.com","numberOfVisits":5,"phoneNumber":"+1 800 354 6783","isMember":false},{"id":"3","name":"Shekhar","email":"Shekhar@jmail.com","numberOfVisits":300,"phoneNumber":"+1 801 643 7265","isMember":true}])";

    string expectedResponseBody = R"([{"isMember":true,"phoneNumber":"+1 804 123 5648","numberOfVisits":155,"email":"rohan@jmail.com","id":"1","name":"Rohan"},{"name":"Vishal","id":"2","email":"Vishal@jmail.com","numberOfVisits":5,"phoneNumber":"+1 800 354 6783","isMember":false},{"isMember":true,"phoneNumber":"+1 801 643 7265","numberOfVisits":300,"email":"Shekhar@jmail.com","id":"3","name":"Shekhar"}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(ResourceAPI<Customer>::resourceMap.size() == 3); // Ensure that no resources were added or removed from the map
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
}

TEST_CASE("Updating a Customer resource") 
{
    // Load resources to update.
    CustomersMap["1"] = Customer{json::load(R"({"id":"1","name":"Rohan","email":"rohan@jmail.com","numberOfVisits":155,"phoneNumber":"+1 804 123 5648","isMember":true})")};
    CustomersMap["2"] = Customer{json::load(R"({"id":"2","name":"Vishal","email":"Vishal@jmail.com","numberOfVisits":5,"phoneNumber":"+1 800 354 6783","isMember":false})")};
    CustomersMap["3"] = Customer{json::load(R"({"id":"3","name":"Shekhar","email":"Shekhar@jmail.com","numberOfVisits":300,"phoneNumber":"+1 801 643 7265","isMember":true})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Customer>::resourceMap = CustomersMap;

    // Setup request object
    request req;
    req.body = R"({"isMember":true,"phoneNumber":"+1 804 123 5648","numberOfVisits":156,"email":"rohan123@jmail.com","id":"1","name":"Rohan"})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Customer>::updateResource(req,res,"1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Customer>::resourceMap.size() == 3); // Ensure no resource was added or removed from the map

    // Validate the resource contents
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getId() == "1"); 
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getName() == "Rohan");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getEmail() == "rohan123@jmail.com");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getNumOfVisits() == 156);
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getPhoneNum() == "+1 804 123 5648");
    CHECK(ResourceAPI<Customer>::resourceMap.at("1").getIsMember() == true);
}

TEST_CASE("Deleting a Customer resource") 
{
    // Load a resources to update.
    CustomersMap["1"] = Customer{json::load(R"({"id":"1","name":"Rohan","email":"rohan@jmail.com","numberOfVisits":155,"phoneNumber":"+1 804 123 5648","isMember":true})")};
    CustomersMap["2"] = Customer{json::load(R"({"id":"2","name":"Vishal","email":"Vishal@jmail.com","numberOfVisits":5,"phoneNumber":"+1 800 354 6783","isMember":false})")};
    CustomersMap["3"] = Customer{json::load(R"({"id":"3","name":"Shekhar","email":"Shekhar@jmail.com","numberOfVisits":300,"phoneNumber":"+1 801 643 7265","isMember":true})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Customer>::resourceMap = CustomersMap;

    // Perform the action
    response res = ResourceAPI<Customer>::deleteResource("3");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Customer>::resourceMap.size() == 2); // Ensure one resource was removed from the map
}


//-----------------------------------------------------------
//CAT

//Endpoint cases for Cat
TEST_CASE("Creating a new Cat resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"dob":"12/29/2022","breed":"Turkish Angora","availableForAdoption":true,"id":"1","rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her.","name":"Meowy"})";

    // Perform the action
    response res = ResourceAPI<Cat>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getName() == "Meowy");
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getBreed() == "Turkish Angora" );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getDob() == "12/29/2022" );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getAvailableForAdoption() == true );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getRescueStory() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her." );
}

TEST_CASE("Reading a Cat resource") 
{
    // Load a resource to read.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Meowy","breed":"Turkish Angora","dob":"12/29/2022","availableForAdoption":true,"rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Perform the action
    response res = ResourceAPI<Cat>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok

    CHECK(res.body == CatsMap["1"].convertToJson().dump()); // Validate the reponse body

    CHECK(ResourceAPI<Cat>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Reading all Cat resources") 
{
    // Load resources to read.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Meowy","breed":"Turkish Angora","dob":"12/29/2022","availableForAdoption":true,"rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna","breed":"Burmese Cat","dob":"05/09/2022","availableForAdoption":false,"rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3","name":"Tashi","breed":"Himalayan Cat","dob":"02/15/2023","availableForAdoption":true,"rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4","name":"Kiki","breed":"Domestic Shorthair","dob":"07/22/2023","availableForAdoption":false,"rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Setup request object
    //request req;

    // Perform the action
    response res = ResourceAPI<Cat>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"dob":"12/29/2022","breed":"Turkish Angora","availableForAdoption":true,"id":"1","rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her.","name":"Meowy"},{"name":"Luna","rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!","id":"2","availableForAdoption":false,"breed":"Burmese Cat","dob":"05/09/2022"},{"dob":"02/15/2023","breed":"Himalayan Cat","availableForAdoption":true,"id":"3","rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured.","name":"Tashi"},{"dob":"07/22/2023","breed":"Domestic Shorthair","availableForAdoption":false,"id":"4","rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him.","name":"Kiki"}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 4); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Updating a Cat resource") 
{
    // Load resources to update.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Meowy","breed":"Turkish Angora","dob":"12/29/2022","availableForAdoption":true,"rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna","breed":"Burmese Cat","dob":"05/09/2022","availableForAdoption":false,"rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3","name":"Tashi","breed":"Himalayan Cat","dob":"02/15/2023","availableForAdoption":true,"rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4","name":"Kiki","breed":"Domestic Shorthair","dob":"07/22/2023","availableForAdoption":false,"rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Setup request object
    request req;
    req.body = R"({"dob":"11/20/2022","breed":"Angora","availableForAdoption":false,"id":"1","rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her.","name":"Astra"})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Cat>::updateResource(req,res,"1");

    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 4); // Ensure no resource was added or removed from the map
    
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getName() == "Astra"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getBreed() == "Angora" );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getDob() == "11/20/2022" );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getAvailableForAdoption() == false );
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getRescueStory() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her." );
}

TEST_CASE("Deleting a Cat resource") 
{
    // Load a resources to update.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Meowy","breed":"Turkish Angora","dob":"12/29/2022","availableForAdoption":true,"rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna","breed":"Burmese Cat","dob":"05/09/2022","availableForAdoption":false,"rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3","name":"Tashi","breed":"Himalayan Cat","dob":"02/15/2023","availableForAdoption":true,"rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4","name":"Kiki","breed":"Domestic Shorthair","dob":"07/22/2023","availableForAdoption":false,"rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Perform the action
    response res = ResourceAPI<Cat>::deleteResource("4");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 3); // Ensure one resource was removed from the map
}




//-----------------------------------------------------------
//CAFE

//Endpoint cases for Cafe
TEST_CASE("Creating a new Cafe resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Cafe>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322","id":"1","name":"Catland Cafe"})"; 

    // Perform the action
    response res = ResourceAPI<Cafe>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cafe>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getName() == "Catland Cafe");
    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getAddress() == "565 Cedar Rd., Suite 12 Chesapeake, VA 23322" );
}

TEST_CASE("Reading a Cafe resource") 
{
    // Load a resource to read.
    CafeMap["1"] = Cafe{json::load(R"({"id":"1", "name" : "Catland Cafe" , "address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Cafe>::resourceMap = CafeMap;

    // Perform the action
    response res = ResourceAPI<Cafe>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok

    CHECK(res.body == CafeMap["1"].convertToJson().dump()); // Validate the reponse body

    CHECK(ResourceAPI<Cafe>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Reading all Cafe resources") 
{
    // Load resources to read.
    CafeMap["1"] = Cafe{json::load(R"({"id":"1","name":"Catland Cafe","address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})")};
    CafeMap["2"] = Cafe{json::load(R"({"id":"2","name":"Kat Kingdom Cafe","address":"214 Juniper Rd., B23, Richmond, VA 23173"})")};
    CafeMap["3"] = Cafe{json::load(R"({"id":"3","name":"Shimi Shimi Cafe","address":"43 Silver Bell Rd., C3, Hola, NY 11293"})")};
    CafeMap["4"] = Cafe{json::load(R"({"id":"4","name":"Meow Cafe","address":"001 Orange Rd., O12, Beha, MD 23412"})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cafe>::resourceMap = CafeMap;

    // Perform the action
    response res = ResourceAPI<Cafe>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322","id":"1","name":"Catland Cafe"},{"name":"Kat Kingdom Cafe","id":"2","address":"214 Juniper Rd., B23, Richmond, VA 23173"},{"address":"43 Silver Bell Rd., C3, Hola, NY 11293","id":"3","name":"Shimi Shimi Cafe"},{"address":"001 Orange Rd., O12, Beha, MD 23412","id":"4","name":"Meow Cafe"}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(ResourceAPI<Cafe>::resourceMap.size() == 4); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Updating a Cafe resource") 
{
    // Load resources to update.
    CafeMap["1"] = Cafe{json::load(R"({"id":"1","name":"Catland Cafe","address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})")};
    CafeMap["2"] = Cafe{json::load(R"({"id":"2","name":"Kat Kingdom Cafe","address":"214 Juniper Rd., B23, Richmond, VA 23173"})")};
    CafeMap["3"] = Cafe{json::load(R"({"id":"3","name":"Shimi Shimi Cafe","address":"43 Silver Bell Rd., C3, Hola, NY 11293"})")};
    CafeMap["4"] = Cafe{json::load(R"({"id":"4","name":"Meow Cafe","address":"001 Orange Rd., O12, Beha, MD 23412"})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cafe>::resourceMap = CafeMap;

    // Setup request object
    request req;
    req.body = R"({"address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322","id":"1","name":"Ma-ah Cafe"})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Cafe>::updateResource(req, res, "1");

    //std::cout << "Actual Response Body when updating cafe: " << res.body << std::endl;

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cafe>::resourceMap.size() == 4); // Ensure no resource was added or removed from the map
    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getName() == "Ma-ah Cafe");
    CHECK(ResourceAPI<Cafe>::resourceMap.at("1").getAddress() == "565 Cedar Rd., Suite 12 Chesapeake, VA 23322");
}

TEST_CASE("Deleting a Cafe resource") 
{
    // Load a resources to update.
    CafeMap["1"] = Cafe{json::load(R"({"id":"1","name":"Catland Cafe","address":"565 Cedar Rd., Suite 12 Chesapeake, VA 23322"})")};
    CafeMap["2"] = Cafe{json::load(R"({"id":"2","name":"Kat Kingdom Cafe","address":"214 Juniper Rd., B23, Richmond, VA 23173"})")};
    CafeMap["3"] = Cafe{json::load(R"({"id":"3","name":"Shimi Shimi Cafe","address":"43 Silver Bell Rd., C3, Hola, NY 11293"})")};
    CafeMap["4"] = Cafe{json::load(R"({"id":"4","name":"Meow Cafe","address":"001 Orange Rd., O12, Beha, MD 23412"})")};
    
    // Setup resource map to be empty before the test
    ResourceAPI<Cafe>::resourceMap = CafeMap;

    // Perform the action
    response res = ResourceAPI<Cafe>::deleteResource("4");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Cafe>::resourceMap.size() == 3); // Ensure one resource was removed from the map
}












//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Food

//Endpoint cases for Foods
TEST_CASE("Creating a new Food resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Food>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"catConsumable":true,"id":"1","qty_g":300,"name":"Salmon bites","cost":12.5})"; 

    // Perform the action
    response res = ResourceAPI<Food>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Food>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Food>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getName() == "Salmon bites");
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getCost() == 12.50 );
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getCatConsumable() == true );
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getQtyG() == 300 );   
}

TEST_CASE("Reading a Food resource") 
{
    // Load a resource to read.
    FoodsMap["1"] = Food{json::load(R"({"id":"1","name":"Salmon bites","cost":12.50,"catConsumable":true,"qty_g":300})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Food>::resourceMap = FoodsMap;

    // Perform the action
    response res = ResourceAPI<Food>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok

    CHECK(res.body == FoodsMap["1"].convertToJson().dump()); // Validate the reponse body

    CHECK(ResourceAPI<Food>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Reading all Food resources") 
{
    // Load resources to read.
    FoodsMap["1"] = Food{json::load(R"({"id":"1","name":"Salmon bites","cost":12.5,"catConsumable":true,"qty_g":300})")};
    FoodsMap["2"] = Food{json::load(R"({"id":"2","name":"Egg Rolls","cost":5.5,"catConsumable":false,"qty_g":300})")};
    FoodsMap["3"] = Food{json::load(R"({"id":"3","name":"Aloo Paratha","cost":15.5,"catConsumable":false,"qty_g":250})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Food>::resourceMap = FoodsMap;

    // Setup request object
    //request req;

    // Perform the action
    response res = ResourceAPI<Food>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"catConsumable":true,"id":"1","qty_g":300,"name":"Salmon bites","cost":12.5},{"cost":5.5,"name":"Egg Rolls","qty_g":300,"id":"2","catConsumable":false},{"catConsumable":false,"id":"3","qty_g":250,"name":"Aloo Paratha","cost":15.5}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(ResourceAPI<Food>::resourceMap.size() == 3); // Ensure that no resources were added or removed from the map
}

// TEST_CASE("Test case for filter option for catConsumable") 
// {
//     // Load resources to read.
//     FoodsMap["1"] = Food{json::load(R"({"id":"1","name":"Salmon bites","cost":12.50,"catConsumable":true,"qty_g":300})")};
//     FoodsMap["2"] = Food{json::load(R"({"id":"2","name":"Egg Rolls","cost":5.50,"catConsumable":false,"qty_g":300})")};
//     FoodsMap["3"] = Food{json::load(R"({"id":"3","name":"Aloo Paratha","cost":15.50,"catConsumable":false,"qty_g":250})")};
//     FoodsMap["4"] = Food{json::load(R"({"id":"4","name":"Bonito flakes soup","cost":11.50,"catConsumable":true,"qty_g":400})")};

//     // Setup resource map to be empty before the test
//     ResourceAPI<Food>::resourceMap = FoodsMap;

//     // Setup request object
//     request req;

//     // Perform the action
//     response res = ResourceAPI<Food>::readAllResources(req);

//     // Create the expected reponse body
//     string expectedResponseBody = R"([{"catConsumable":true,"id":"1","qty_g":300,"name":"Salmon bites","cost":12.5},{"catConsumable":true,"id":"4","qty_g":400,"name":"Bonito flakes soup","cost":11.5}])";

//     std::cout << "Actual Response Body: " << res.body << std::endl;

//     // Check the results
//     CHECK(res.code == 200); // Check that the response code is 200 Ok
//     CHECK(res.body == expectedResponseBody); // Validate the reponse body
//     CHECK(ResourceAPI<Food>::resourceMap.size() == 4); // Ensure that no resources were added or removed from the map
// }

TEST_CASE("Updating a Food resource") 
{
    // Load resources to update.
    FoodsMap["1"] = Food{json::load(R"({"id":"1","name":"Salmon bites","cost":12.5,"catConsumable":true,"qty_g":300})")};
    FoodsMap["2"] = Food{json::load(R"({"id":"2","name":"Egg Rolls","cost":5.5,"catConsumable":false,"qty_g":300})")};
    FoodsMap["3"] = Food{json::load(R"({"id":"3","name":"Aloo Paratha","cost":15.5,"catConsumable":false,"qty_g":250})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Food>::resourceMap = FoodsMap;

    // Setup request object
    request req;
    req.body = R"({"catConsumable":true,"id":"1","qty_g":300,"name":"Salmon bites","cost":12.5})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Food>::updateResource(req,res,"1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Food>::resourceMap.size() == 3); // Ensure no resource was added or removed from the map
    
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getName() == "Salmon bites");
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getCost() == 12.5);
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getCatConsumable() == true );
    CHECK(ResourceAPI<Food>::resourceMap.at("1").getQtyG() == 300 );  
    }
    

TEST_CASE("Deleting a Food resource") 
{
    // Load a resources to update.
    FoodsMap["1"] = Food{json::load(R"({"id":"1","name":"Salmon bites","cost":12.50,"catConsumable":true,"qty_g":300})")};
    FoodsMap["2"] = Food{json::load(R"({"id":"2","name":"Egg Rolls","cost":5.50,"catConsumable":false,"qty_g":300})")};
    FoodsMap["3"] = Food{json::load(R"({"id":"3","name":"Aloo Paratha","cost":15.50,"catConsumable":false,"qty_g":250})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Food>::resourceMap = FoodsMap;

    // Perform the action
    response res = ResourceAPI<Food>::deleteResource("3");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Food>::resourceMap.size() == 2); // Ensure one resource was removed from the map
}







//-----------------------------------------------------------
//Drink

//Endpoint cases for Drinks
TEST_CASE("Creating a new Drink resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Drink>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"qty_ml":155,"catConsumable":true,"id":"1","name":"Whole Milk","cost":10.0})"; 

    // Perform the action
    response res = ResourceAPI<Drink>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Drink>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getName() == "Whole Milk");
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getCost() ==  10.0 );
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getCatConsumable() == true);
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getQtyMl() == 155);   
}

TEST_CASE("Reading a Drink resource") 
{
    // Load a resource to read.
    DrinksMap["1"] = Drink{json::load(R"({"id":"1","name":"Whole Milk","cost":10.0,"catConsumable":true,"qty_ml":155})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Drink>::resourceMap = DrinksMap;

    // Perform the action
    response res = ResourceAPI<Drink>::readResource("1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok

    CHECK(res.body == DrinksMap["1"].convertToJson().dump()); // Validate the reponse body

    CHECK(ResourceAPI<Drink>::resourceMap.size() == 1); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Reading all Drink resources") 
{
    // Load resources to read.
    DrinksMap["1"] = Drink{json::load(R"({"id":"1","name":"Whole Milk","cost":10.0,"catConsumable":true,"qty_ml":155})")};
    DrinksMap["2"] = Drink{json::load(R"({"id":"2","name":"Original Boba","cost":14.0,"catConsumable":false,"qty_ml":150})")};
    DrinksMap["3"] = Drink{json::load(R"({"id":"3","name":"Pepsi","cost":13.0,"catConsumable":false,"qty_ml":155})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Drink>::resourceMap = DrinksMap;

    // Setup request object
    //request req;

    // Perform the action
    response res = ResourceAPI<Drink>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"qty_ml":155,"catConsumable":true,"id":"1","name":"Whole Milk","cost":10.0},{"cost":14.0,"name":"Original Boba","id":"2","catConsumable":false,"qty_ml":150},{"qty_ml":155,"catConsumable":false,"id":"3","name":"Pepsi","cost":13.0}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(ResourceAPI<Drink>::resourceMap.size() == 3); // Ensure that no resources were added or removed from the map
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
}


TEST_CASE("Updating a Drink resource") 
{
    // Load resources to update.
    DrinksMap["1"] = Drink{json::load(R"({"id":"1","name":"Whole Milk","cost":10.0,"catConsumable":true,"qty_ml":155})")};
    DrinksMap["2"] = Drink{json::load(R"({"id":"2","name":"Original Boba","cost":14.0,"catConsumable":false,"qty_ml":150})")};
    DrinksMap["3"] = Drink{json::load(R"({"id":"3","name":"Pepsi","cost":13.0,"catConsumable":false,"qty_ml":155})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Drink>::resourceMap = DrinksMap;

    // Setup request object
    request req;
    req.body = R"({"qty_ml":155,"catConsumable":true,"id":"1","name":"Whole Milk","cost":10.0})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Drink>::updateResource(req,res,"1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Drink>::resourceMap.size() == 3); // Ensure no resource was added or removed from the map
    
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getName() == "Whole Milk");
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getCost() ==  10.0 );
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getCatConsumable() == true);
    CHECK(ResourceAPI<Drink>::resourceMap.at("1").getQtyMl() == 155);   
    }

TEST_CASE("Deleting a Drink resource") 
{
    // Load a resources to update.
    DrinksMap["1"] = Drink{json::load(R"({"id":"1","name":"Whole Milk","cost":10.0,"catConsumable":true,"qty_ml":155})")};
    DrinksMap["2"] = Drink{json::load(R"({"id":"2","name":"Original Boba","cost":14.0,"catConsumable":false,"qty_ml":150})")};
    DrinksMap["3"] = Drink{json::load(R"({"id":"3","name":"Pepsi","cost":13.0,"catConsumable":false,"qty_ml":155})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Drink>::resourceMap = DrinksMap;

    // Perform the action
    response res = ResourceAPI<Drink>::deleteResource("3");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Drink>::resourceMap.size() == 2); // Ensure one resource was removed from the map
}