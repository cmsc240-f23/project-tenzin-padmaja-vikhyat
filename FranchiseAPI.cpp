#include <crow.h>
#include <map>
#include <string>

#include "ResourceAPI.h"
#include "FileIO.h"
#include "FileIO.cpp"
#include "Cat.h"
// #include "Cafe.h"
#include "Customer.h"
// #include "Consumable.h"
// #include "Food.h"
// #include "Drink.h"
// #include "CatProduct.h"

using namespace std;
using namespace crow;

// load everything into maps


int main(){
    cout<<"Started up server"<<endl;
    // set the maps for the static API classes
    ResourceAPI<Cat>::resourceMap = loadFromFile<Cat>((string) "Cats.json");
    // ResourceAPI<Cafe>::resourceMap = loadFromFile<Cafe>((string) "Cafes.json");
    ResourceAPI<Customer>::resourceMap = loadFromFile<Customer>((string) "Customers.json");
    // ResourceAPI<Food>::resourceMap = loadFromFile<Food>((string) "Foods.json");
    // ResourceAPI<Drink>::resourceMap = loadFromFile<Drink>((string) "Drinks.json");

    cout<<"Loaded files"<<endl;
    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Cat resource.
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::POST)(ResourceAPI<Cat>::createResource);
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readAllResources);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readResource);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Cat>::updateResource); // we never really need to update a cat
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Cat>::deleteResource);

    // Define endpoints and CRUD methods for the Cat resource.
    CROW_ROUTE(app, "/api/customers").methods(HTTPMethod::POST)(ResourceAPI<Customer>::createResource);
    CROW_ROUTE(app, "/api/customers").methods(HTTPMethod::GET)(ResourceAPI<Customer>::readAllResources);
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::GET)(ResourceAPI<Customer>::readResource);
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Customer>::updateResource); // we never really need to update a customer
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Customer>::deleteResource);

    // Run the web service app
    app.port(13579).run();

//     // save everything
    saveToFile(ResourceAPI<Cat>::resourceMap, "Cats.json");
    // saveToFile(ResourceAPI<Cafe>::resourceMap, "Cafes.json");
    saveToFile(ResourceAPI<Customer>::resourceMap, "Customers.json");
    // saveToFile(ResourceAPI<Food>::resourceMap, "Foods.json");
    // saveToFile(ResourceAPI<Drink>::resourceMap, "Drinks.json");

    return 0;
}