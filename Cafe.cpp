#include <iostream>
#include <string>
#include <crow.h>
#include <map>
#include "Cat.h"
#include "Customer.h"
#include "CatProduct.h"
#include "Food.h"
#include "Drink.h"

using namespace std;
using namespace crow;

extern map<std::string, Customer> CustomersMap;
extern map<std::string, Cat> CatsMap;

Cafe::Cafe(json::rvalue readValueJson)
{
    updateFromJson(readValueJson);
}
json::wvalue Cafe::convertToJson() 
{
    json::wvalue writeJson;
    writeJson["id"] = id;
    writeJson["name"] = name;
    writeJson["address"] = address;
    writeJson["cats"] = catVector;
    //writeJson["foods"] = foodVector;
    //writeJson["drinks"] = drinkVector;
   // writeJson["products"] = productVector;
   
    writeJson["totalDonation"] = totalDonation;
    //writeJson["customers"] = customerVector;
    
    // Convert artists to json (Save only the ids)
    int index1 = 0;
    for (Food food : foods) 
    {
        writeJson["foods"][index1]["id"] = food.getId();
    }
    int index2 = 0;
    for (Drink drink : drinks) 
    {
        writeJson["drinks"][index2]["id"] = drink.getId();
    }
    int index3 = 0;
    for (CatProduct product : products) 
    {
        writeJson["products"][index3]["id"] = product.getId();
    }
    int index4 = 0;
    for (Cat cat : cats) 
    {
        writeJson["cats"][index4]["id"] = cat.getId();
    }
    int index5 = 0;
    for (Customer customer : customers) 
    {
        writeJson["customers"][index5]["id"] = customer.getId();
    }

    // // If you want the full json for each artist to be included:
    // for (Artist artist : artists) 
    // {
    //     writeJson["artists"] = artist.convertToJson();
    // }

    return writeJson;
}

void Cafe::updateFromJson(json::rvalue readValueJson) 
{
    id = readValueJson["id"].s();
    name = readValueJson["name"].s();
    totalDonation= readValueJson["totalDonation"].d();

    for (json::rvalue foodReadValueJson: readValueJson["foods"])
    {
        foods.push_back(foodsMap.at(foodReadValueJson["id"].s()));
    }
    for (json::rvalue drinkReadValueJson: readValueJson["drinks"])
    {
        drinks.push_back(drinksMap.at(drinkReadValueJson["id"].s()));
    }
    for (json::rvalue productReadValueJson: readValueJson["products"])
    {
        products.push_back(productsMap.at(productReadValueJson["id"].s()));
    }
     for (json::rvalue customerReadValueJson: readValueJson["customers"])
    {
        customers.push_back(customersMap.at(customerReadValueJson["id"].s()));
    }
     for (json::rvalue catReadValueJson: readValueJson["cats"])
    {
        cats.push_back(catsMap.at(catReadValueJson["id"].s()));
    }


}
