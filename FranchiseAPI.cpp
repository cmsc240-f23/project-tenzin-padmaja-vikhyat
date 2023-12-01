#include <crow.h>
#include <map>
#include <string>

#include "ResourceAPI.h"
#include "FileIO.h"
#include "FileIO.cpp"
#include "Cat.h"
#include "Cat.cpp"

// #include "CatProduct.h"
// #include "Food.h"
// #include "Drink.h"
// #include "Customer.h"

using namespace std;
using namespace crow;

// load everything into maps

response testFunction(request req){
    return response();
}

int main(){

    // set the maps for the static API classes
    ResourceAPI<Cat>::resourceMap = loadFromFile<Cat>((string) "Cats.json");

    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Cat resource.
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::POST)(ResourceAPI<Cat>::createResource);
    // CROW_ROUTE(app, "/api/cats").methods("POST"_method)(ResourceAPI<Cat>::createResource);
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readAllResources);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readResource);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Cat>::updateResource); // we never really need to update a cat
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Cat>::deleteResource);

    // Run the web service app
    app.port(13579).run();

//     // save everything
    saveToFile(ResourceAPI<Cat>::resourceMap, "Cats.json");

    return 0;
}