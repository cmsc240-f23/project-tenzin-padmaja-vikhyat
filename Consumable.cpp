#include "Consumable.h"
#include <crow.h>

using namespace std;
using namespace crow;

Consumable::Consumable(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}


// Convert to JSON
json::wvalue Consumable::convertToJson() 
{
    json::wvalue writeJson;
    
    // Add Record-specific details
    writeJson["name"] = name;
    writeJson["cost"] = cost;
    writeJson["id"] = id;
    writeJson["catConsumable"] = (catConsumable ? true : false);

    return writeJson;
}

// Update from JSON
void Consumable::updateFromJson(json::rvalue readValueJson) 
{
    // Update Record-specific details
    name = readValueJson["name"].s();
    cost = readValueJson["cost"].d(); // Convert to double
    id = readValueJson["id"].s();
    catConsumable = readValueJson["catConsumable"].b();
}
