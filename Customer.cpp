#include "Customer.h"

using namespace std;
using namespace crow;

Customer::Customer(json::rvalue readValueJson)  
{
    updateFromJson(readValueJson);
}

// Convert to JSON
json::wvalue Customer::convertToJson() 
{
    json::wvalue writeJson;
    
    writeJson["id"] = id;
    writeJson["name"] = name;
    writeJson["email"] = email;
    writeJson["numberOfVisits"] = numberOfVisits;
    writeJson["phoneNumber"] = phoneNumber;
    writeJson["isMember"] = isMember;
    
    return writeJson;
}

// Update from JSON
void Customer::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    email = readValueJson["email"].s();
    name = readValueJson["name"].s();
    numberOfVisits  = readValueJson["numberOfVisits"].i();
    phoneNumber = readValueJson["phoneNumber"].s();
    isMember = readValueJson["isMember"].b();
}

