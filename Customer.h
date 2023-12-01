#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <crow.h>

class Customer
{
    public:
        Customer() {}
        Customer(crow::json::rvalue readValueJson);
        //void buy(T item)

        //getter
        std::string getId() const { return id; }
        
        //setter
        void setId(std::string idParam) { id = idParam; }

        //convert to JSON
        crow::json::wvalue convertToJson();

        //update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);
    private:
        std::string name;
        std::string email;
        std::string id;
        bool isMember;
        int numberOfVisits;
        //vector <T> purchasedItems;
        std::string phoneNumber;

};
#endif