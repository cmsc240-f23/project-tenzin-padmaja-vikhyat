#include "CatProduct.h"

using namespace std;
using namespace crow;


CatProduct::CatProduct(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}


// Convert to JSON
json::wvalue CatProduct::convertToJson() 
{

    // Add Record-specific details
    writeJson["name"] = name;
    writeJson["cost"] = cost;
    writeJson["id"] = id;

    return writeJson;
}

// Update from JSON
void CatProduct::updateFromJson(json::rvalue readValueJson) 
{

    // Update Record-specific details
    name = readValueJson["name"].s();
    cost = readValueJson["cost"].s();
    id = readValueJson["id"].s();
}
