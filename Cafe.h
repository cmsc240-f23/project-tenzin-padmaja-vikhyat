#ifndef CAFE_H
#define CAFE_H

#include <crow.h>
#include <iostream>
#include <string>

class Cafe
{
    public:
        // Constructors
        Cafe() {}
        Cafe(crow::json::rvalue readValueJson);
        
        // Getters
        std::string getId() const { return id; }
        std::string getName() const { return name; }
        std::string getAddress() const { return address; }

        // Setters
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setAddress(std::string addressParam) { name = addressParam; }

        // Convert to JSON
        crow::json::wvalue convertToJson();

        // Update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);
        
    private:
        std::string id;
        std::string name;
        std::string address;
};

#endif
