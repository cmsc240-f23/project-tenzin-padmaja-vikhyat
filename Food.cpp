#include "Food.h"

using namespace std;
using namespace crow;


Food::Food(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}


// Convert to JSON
json::wvalue Consumable::convertToJson() 
{

    // Add Record-specific details
    writeJson["qty_g"] = qty_g;

    return writeJson;
}

// Update from JSON
void Food::updateFromJson(json::rvalue readValueJson) 
{

    // Update Record-specific details
    qty_g = readValueJson["qty_g"].i();
}
