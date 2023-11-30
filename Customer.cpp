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
    writeJson["customerName"] = customerName;
    writeJson["customerEmail"] = customerEmail;
    writeJson["numberOfVisits"] = numberOfVisits;
    writeJson["phoneNumber"] = phoneNumber;
    writeJson["isMember"] = isMember;
    
    return writeJson;
}

// Update from JSON
void Customer::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    customerEmail = readValueJson["customerEmail"].s();
    customerName = readValueJson["customerName"].s();
    numberOfVisits  = readValueJson["numberOfVisits"].i();
    phoneNumber = readValueJson["phoneNumber"].s();
    isMember = readValueJson["phoneNumber"].b();
}

