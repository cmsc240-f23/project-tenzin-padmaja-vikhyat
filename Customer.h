#include <iostream>
#include <string>
#include <crow.h>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
    public:
        Customer() {}
        Customer(crow::json::rvalue readValueJson);
        //void buy(T item)
        string getId() const { return id; }
        void setId(std::string idParam) { id = idParam; }
        crow::json::wvalue convertToJson();
        void updateFromJson(crow::json::rvalue readValueJson);
    private:
        string customerName;
        string customerEmail;
        string id;
        bool isMember;
        int numberOfVisits;
        //vector <T> purchasedItems;
        string phoneNumber;

};
#endif