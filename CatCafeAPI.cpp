#include <crow.h>
#include <map>
#include <string>

#include "ResourceAPI.h"
#include "FileIO.h"
#include "FileIO.cpp"
#include "Cat.h"
#include "Cafe.h"
#include "Customer.h"
// #include "Consumable.h"
#include "Food.h"
#include "Drink.h"

using namespace std;
using namespace crow;

int main(){
    cout << "Started up server" << endl;

    // set the maps for the static API classes
    ResourceAPI<Cat>::resourceMap = loadFromFile<Cat>((string) "Cats.json");
    ResourceAPI<Cafe>::resourceMap = loadFromFile<Cafe>((string) "Cafe.json");
    ResourceAPI<Customer>::resourceMap = loadFromFile<Customer>((string) "Customers.json");
    ResourceAPI<Food>::resourceMap = loadFromFile<Food>((string) "Foods.json");
    ResourceAPI<Drink>::resourceMap = loadFromFile<Drink>((string) "Drinks.json");
    cout << "Loaded files" << endl;

    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Cat resource.
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::POST)(ResourceAPI<Cat>::createResource);
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readAllResources);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readResource);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Cat>::updateResource); // we never really need to update a cat
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Cat>::deleteResource);

    // Define endpoints and CRUD methods for the Customer resource.
    CROW_ROUTE(app, "/api/customers").methods(HTTPMethod::POST)(ResourceAPI<Customer>::createResource);
    CROW_ROUTE(app, "/api/customers").methods(HTTPMethod::GET)(ResourceAPI<Customer>::readAllResources);
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::GET)(ResourceAPI<Customer>::readResource);
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Customer>::updateResource);
    CROW_ROUTE(app, "/api/customers/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Customer>::deleteResource);
    
    // Define endpoints and CRUD methods for the Cafe resource.
    CROW_ROUTE(app, "/api/cafe").methods(HTTPMethod::POST)(ResourceAPI<Cafe>::createResource);
    CROW_ROUTE(app, "/api/cafe/<string>").methods(HTTPMethod::GET)(ResourceAPI<Cafe>::readResource);
    CROW_ROUTE(app, "/api/cafe/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Cafe>::updateResource);

    // Define endpoints and CRUD methods for the Food resource.
    CROW_ROUTE(app, "/api/foods").methods(HTTPMethod::POST)(ResourceAPI<Food>::createResource);
    CROW_ROUTE(app, "/api/foods").methods(HTTPMethod::GET)(ResourceAPI<Food>::readAllResources);
    CROW_ROUTE(app, "/api/foods/<string>").methods(HTTPMethod::GET)(ResourceAPI<Food>::readResource);
    CROW_ROUTE(app, "/api/foods/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Food>::updateResource);
    CROW_ROUTE(app, "/api/foods/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Food>::deleteResource);

    // Define endpoints and CRUD methods for the Drink resource.
    CROW_ROUTE(app, "/api/drinks").methods(HTTPMethod::POST)(ResourceAPI<Drink>::createResource);
    CROW_ROUTE(app, "/api/drinks").methods(HTTPMethod::GET)(ResourceAPI<Drink>::readAllResources);
    CROW_ROUTE(app, "/api/drinks/<string>").methods(HTTPMethod::GET)(ResourceAPI<Drink>::readResource);
    CROW_ROUTE(app, "/api/drinks/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Drink>::updateResource);
    CROW_ROUTE(app, "/api/drinks/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Drink>::deleteResource);

    // Run the web service app
    app.port(13579).run();

//     // save everything
    saveToFile(ResourceAPI<Cat>::resourceMap, "Cats.json");
    // saveToFile(ResourceAPI<Cafe>::resourceMap, "Cafes.json");
    saveToFile(ResourceAPI<Customer>::resourceMap, "Customers.json");
    saveToFile(ResourceAPI<Food>::resourceMap, "Foods.json");
    saveToFile(ResourceAPI<Drink>::resourceMap, "Drinks.json");

    return 0;
}