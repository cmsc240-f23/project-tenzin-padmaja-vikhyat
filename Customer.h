#include <iostream>
#include <string>
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H
template <typename T>
class Customer
{
    public:
        void buy(T item);
        int getId();
        void convertToJson();
        void updateFromJson();

    private:
        string customerName;
        string customerEmail;
        int id;
        bool isMember;
        int numberOfVisits;
        purchasedItems;
        string phoneNumber;

};
#endif