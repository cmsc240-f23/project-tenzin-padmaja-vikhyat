#include "Food.h"

using namespace std;
using namespace crow;

Food::Food(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Food::convertToJson() 
{
    json::wvalue writeJson = Consumable::convertToJson();

    // Add Food-specific details
    writeJson["qty_g"] = qty_g;

    return writeJson;
}

// Update from JSON
void Food::updateFromJson(json::rvalue readValueJson) 
{   
    Consumable::updateFromJson(readValueJson); 
    // Update Food-specific details
    qty_g = readValueJson["qty_g"].i();
}
