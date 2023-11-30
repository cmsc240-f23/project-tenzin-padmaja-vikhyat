#include "Drink.h"

using namespace std;
using namespace crow;


Drink::Drink(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}


// Convert to JSON
json::wvalue Drink::convertToJson() 
{

    // Add Record-specific details
    writeJson["qty_ml"] = qty_ml;

    return writeJson;
}

// Update from JSON
void Drink::updateFromJson(json::rvalue readValueJson) 
{

    // Update Record-specific details
    qty_ml = readValueJson["qty_ml"].i();
}
