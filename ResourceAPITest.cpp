#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <crow.h>
#include <doctest.h>
#include "Cat.h"
#include "Cafe.h"
#include "ResourceAPI.h"
#include "Customer.h"
#include "Consumable.h"

using namespace std;
using namespace crow;

map<string, Cat> CatsMap;
map<string, Cafe> CafeMap; //are we having this??
map<string, Customer> CustomersMap;
map<string, Consumable> ConsumablesMap;

TEST_CASE("Creating a new Cat resource") 
{
    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap.clear();

    // Setup request object
    request req;
    req.body = R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})"; 

    // Perform the action
    response res = ResourceAPI<Cat>::createResource(req);

    // Check the results
    CHECK(res.code == 201); // Check that the response code is 201 Created
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 1); // Ensure the resource was added to the map

    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getName() == "Meowy");
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getBreed() == "Turkish Angora" );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getDob() == "12/29/2022" );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getAvailableForAdoption() == true );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getRescueStory() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her." );
}

TEST_CASE("Reading a Cat resource") 
{
    // Load a resource to read.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};

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
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":"false", "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3", "name": "Tashi", "breed": "Himalayan Cat", "dob":"02/15/2023", "availableForAdoption":"true", "rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4", "name": "Kiki", "breed": "Domestic Shorthair", "dob":"07/22/2023", "availableForAdoption":"false", "rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Perform the action
    response res = ResourceAPI<Cat>::readAllResources();

    // Create the expected reponse body
    string expectedResponseBody = R"([{"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."},
                                     {"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":"false", "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"},
                                     {"id":"3", "name": "Tashi", "breed": "Himalayan Cat", "dob":"02/15/2023", "availableForAdoption":"true", "rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."},
                                     {"id":"4", "name": "Kiki", "breed": "Domestic Shorthair", "dob":"07/22/2023", "availableForAdoption":"false", "rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."}])";

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == expectedResponseBody); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 4); // Ensure that no resources were added or removed from the map
}

TEST_CASE("Updating a Cat resource") 
{
    // Load resources to update.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":"false", "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3", "name": "Tashi", "breed": "Himalayan Cat", "dob":"02/15/2023", "availableForAdoption":"true", "rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4", "name": "Kiki", "breed": "Domestic Shorthair", "dob":"07/22/2023", "availableForAdoption":"false", "rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};


    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Setup request object
    request req;
    req.body = R"({"id":"1", "name":"Astra", "breed":"Angora", "dob":"11/20/2022", "availableForAdoption":"false", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})"; 

    // Setup a response object
    response res;

    // Perform the action
    ResourceAPI<Cat>::updateResource(req, res, "1");

    // Check the results
    CHECK(res.code == 200); // Check that the response code is 200 Ok
    CHECK(res.body == req.body); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 4); // Ensure no resource was added or removed from the map
    
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getId() == "1"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getName() == "Astra"); // Validate the resource content
    CHECK(ResourceAPI<Cat>::resourceMap.at("1").getBreed() == "Angora" );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getDob() == "11/20/2022" );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getAvailableForAdoption() == false );
    CHECK (ResourceAPI<Cat>::resourceMap.at("1").getRescueStory() == "This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her." );
}

TEST_CASE("Deleting a Cat resource") 
{
    // Load a resources to update.
    CatsMap["1"] = Cat{json::load(R"({"id":"1","name":"Moewy", "breed":"Turkish Angora", "dob":"12/29/2022", "availableForAdoption":"true", "rescueStory":"This kitty was rescued from a trash outside a grocery store. Her eyes and nose were stuck shut with mucus and it was a really cold winter night when we found her."})")};
    CatsMap["2"] = Cat{json::load(R"({"id":"2","name":"Luna", "breed":"Burmese Cat", "dob":"05/09/2022", "availableForAdoption":"false", "rescueStory":"This kitty was abandoned outside our cafe in a cardboard box and a note that said please adopt me!"})")};
    CatsMap["3"] = Cat{json::load(R"({"id":"3", "name": "Tashi", "breed": "Himalayan Cat", "dob":"02/15/2023", "availableForAdoption":"true", "rescueStory":"This kitty was abdandoned on the side of the highway road 65 and her legs were injured."})")};
    CatsMap["4"] = Cat{json::load(R"({"id":"4", "name": "Kiki", "breed": "Domestic Shorthair", "dob":"07/22/2023", "availableForAdoption":"false", "rescueStory":"This kitty was never picked up from the vet office and the owner abandoned him."})")};

    // Setup resource map to be empty before the test
    ResourceAPI<Cat>::resourceMap = CatsMap;

    // Perform the action
    response res = ResourceAPI<Cat>::deleteResource("4");

    // Check the results
    CHECK(res.code == 204); // Check that the response code is 204 No Content
    CHECK(res.body == ""); // Validate the reponse body
    CHECK(ResourceAPI<Cat>::resourceMap.size() == 3); // Ensure one resource was removed from the map
}