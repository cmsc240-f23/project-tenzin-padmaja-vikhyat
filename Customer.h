#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <crow.h>

class Customer
{
    public:
        // Constructors
        Customer() {}
        Customer(crow::json::rvalue readValueJson);
        
        // Getters
        std::string getId() const { return id; }
        std::string getName() const { return name; }
        std::string getEmail() const { return email; }
        bool getIsMember() const { return isMember; }
        int getNumOfVisits() const { return numberOfVisits; }
        std::string getPhoneNum() const { return phoneNumber; }
        
        // Setter
        void setId(std::string idParam) { id = idParam; }
        void setName(std::string nameParam) { name = nameParam; }
        void setEmail(std::string emailParam) { email = emailParam; }
        void setIsMember(bool memberParam) { isMember = memberParam; }
        void setNumOfVisits(int numOfVisitsParam) { numberOfVisits = numOfVisitsParam; }
        void setPhoneNum(std::string phoneNumberParam) {  phoneNumber = phoneNumberParam; }

        // Convert to JSON
        crow::json::wvalue convertToJson();

        //update from JSON
        void updateFromJson(crow::json::rvalue readValueJson);

    private:
        std::string name;
        std::string email;
        std::string id;
        bool isMember;
        int numberOfVisits;
        std::string phoneNumber;

};
#endif