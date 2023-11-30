#include <crow.h>
#include "ResourceAPI.h"
#include "FileIO.h"
#include "Cat.h"
#include "CatProduct.h"
#include "Food.h"
#include "Drink.h"
#include "Customer.h"

using namespace crow;

// load everything into maps

int main(){

    // set the maps for the static API classes

    // Setup the simple web service.
    SimpleApp app;

    // Define endpoints and CRUD methods for the Cat resource.
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::POST)(ResourceAPI<Cat>::createResource);
    CROW_ROUTE(app, "/api/cats").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readAllResources);
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::GET)(ResourceAPI<Cat>::readResource);
    // CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::PUT)(ResourceAPI<Cat>::updateResource); // we never really need to update a cat
    CROW_ROUTE(app, "/api/cats/<string>").methods(HTTPMethod::DELETE)(ResourceAPI<Cat>::deleteResource);

    // Run the web service app
    app.port(13579).run();

    // save everything
    FileIO::

    return 0;
}