#include "Consumable.h"

using namespace std;
using namespace crow;


Consumable::Consumable(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}


// Convert to JSON
json::wvalue Consumable::convertToJson() 
{

    // Add Record-specific details
    writeJson["name"] = name;
    writeJson["cost"] = cost;
    writeJson["id"] = id;

    return writeJson;
}

// Update from JSON
void Consumable::updateFromJson(json::rvalue readValueJson) 
{

    // Update Record-specific details
    name = readValueJson["name"].s();
    cost = readValueJson["cost"].i();
    id = readValueJson["id"].s();
}
