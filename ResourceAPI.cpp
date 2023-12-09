#include <crow.h>
#include "ResourceAPI.h"
#include "Cat.h"
#include "Cafe.h"
#include "Customer.h"
#include "Food.h"
#include "Drink.h"
#include <vector>
#include <string>

using namespace std;
using namespace crow;

template<typename T> 
map<string, T> ResourceAPI<T>::resourceMap;
    
//Create
template <typename T>
response ResourceAPI<T>::createResource(request req){
    // Load the request body string into a JSON read value.
    json::rvalue readValueJson = json::load(req.body);

    // If there was a problem converting the body text to JSON return an error.
    if (!readValueJson) 
        return response(400, "Invalid JSON");
    
    // Create a new resource.
    try
    {
        T resource{readValueJson};
        // Add the new resource to the map.
        resourceMap[resource.getId()] = resource;
        // Return the created resource as a JSON string.
        return response(201, resource.convertToJson());
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " ... your specs probably didn't match the resource attributes" << '\n';
        return response(400, "Bad request: the body JSON did not match the resource structure");
    }
}

// //OLD PERFECT Read All
// template<typename T> 
// response ResourceAPI<T>::readAllResources(request req) 
// {
//     // Create a new JSON write value use to write to the file.
//     json::wvalue jsonWriteValue;
    
//     // For each resource in the map, convert the resource to JSON and add to the write value.
//     int index = 0;
//     for (pair<string, T> keyValuePair : resourceMap)
//     {
//         // first: gives you access to the first item in the pair.
//         // second: gives you access to the second item in the pair.
//         jsonWriteValue[index] = keyValuePair.second.convertToJson();
//         index++;
//     }

//     return response(jsonWriteValue.dump());
// }

// //NEW INTERMEDIARY Read All
// template<typename T> 
// response ResourceAPI<T>::readAllResources(request req) 
// {
//     // Create a new JSON write value use to write to the file.
//     json::wvalue jsonWriteValue;
    
//     // For each resource in the map, convert the resource to JSON and add to the write value.
//     int index = 0;
//     for (pair<string, T> keyValuePair : resourceMap)
//     {
//         // first: gives you access to the first item in the pair.
//         // second: gives you access to the second item in the pair.
//         jsonWriteValue[index] = keyValuePair.second.convertToJson();
//         index++;
//     }

//     return response(jsonWriteValue.dump());
// }

//readall for the filter
template <typename T>
response ResourceAPI<T>::readAllResources(request req){
    // Create a new JSON write value use to write to the file.
    //cout << "I've reached the read all function in the server" << endl;
    json::wvalue jsonWriteValue;
    int index = 0;
    string catConsumable_i;

    if (req.url_params.get("catConsumable")){
        cout << "ou a cat filtering request!" << endl;
        string clientFilter = req.url_params.get("catConsumable");
        try{
            // For each resource in the map, convert it to JSON and add to the write value.
            json::wvalue thisResource;
            vector<string> keys;
            for (pair<string, T> keyValuePair : resourceMap)
            {   
                thisResource = keyValuePair.second.convertToJson();
                catConsumable_i = (thisResource["catConsumable"].dump()=="true" ? "true" : "false");
                if (catConsumable_i==clientFilter){
                    jsonWriteValue[index] = keyValuePair.second.convertToJson();
                    index++;
                }
            }
            return response(jsonWriteValue.dump());
        }
        catch (exception& e){
            return response(400, "The given resource does not have an attribute catConsumable");
        }
    }

    // For each resource in the map, convert it to JSON and add to the write value.
    for (pair<string, T> keyValuePair : resourceMap)
    {
        jsonWriteValue[index] = keyValuePair.second.convertToJson();
        index++;
    }

    return response(jsonWriteValue.dump());
}

//Read specific
template <typename T>
response ResourceAPI<T>::readResource(string id){
    //cout << "I've reached the read one resource of id function in the server" << endl;
    try 
    {
        //cout << "number of values in my map:" << resourceMap.size() << endl;
        // Get the resource from the resources map.
        T resource = resourceMap.at(id);

        // Return the resource as a JSON string.
        return response(resource.convertToJson().dump());
    } 
    catch (out_of_range& exception) 
    {
        // If the resource was not found in the map return a 404 not found error.
        return response(404, "Resource Not Found");
    }
}

//Update
template <typename T>
void ResourceAPI<T>::updateResource(request req, response& res, string id){
    try 
    {
        // Get the resource from the resources map.
        T resource = resourceMap.at(id);

        // Convert the request body to JSON.
        json::rvalue readValueJson = json::load(req.body);

        // If there was a problem converting the body text to JSON return an error.
        if (!readValueJson) 
        {
            res.code = 400;
            res.end("Invalid JSON");
            return;
        }

        // Update the resource.
        resource.updateFromJson(readValueJson);
        resourceMap[id] = resource;

        // Return the updated resource as a JSON string.
        res.code = 200;
        res.set_header("Content-Type", "application/json");
        res.write(resource.convertToJson().dump());
        res.end();
    } 
    catch (out_of_range& exception) 
    {
        // If the resource was not found in the map return a 404 not found error.
        res.code = 404;
        res.end("Resource Not Found");
    }
}

//Delete
template <typename T>
response ResourceAPI<T>::deleteResource(string id){
    try 
    {
        // Get the resource from the resource map.
        T resource = resourceMap.at(id);

        // Remove the resource from the resources map.
        resourceMap.erase(id);

        // Return a successful code 204 which means success but no content to return.
        return response(204);
    } 
    catch (out_of_range& exception) 
    {
        // If the resource was not found in the map return a 404 not found error.
        return response(404, "Resource not found");
    }
}

template class ResourceAPI<Cat>;
template class ResourceAPI<Cafe>;
template class ResourceAPI<Customer>;
template class ResourceAPI<Food>;
template class ResourceAPI<Drink>;