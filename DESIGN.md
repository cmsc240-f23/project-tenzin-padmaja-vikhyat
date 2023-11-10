# Project Design Document

## Introduction

The web service will be used to operate a cat cafe where customers can spend time with cats, get food/drinks for themselves or for the cats, buy merch/toys, and also adopt rescued cats.

## Background/Context

The web service is designed to address the interest in cat adoption and catering needs of both cat enthusiasts and potential cat owners. Additionally, it’s also meant to inform people about animal rescue and adoption. 

Cat cafes are becoming an increasingly popular type of cafe: they allow visitors to come play with cats sheltered by the cafe, eat and drink at the cafe, buy merch, and also potentially adopt the cats. These cafes process hundreds of transactions everyday, and must maintain information on all their cats, since potential adopters would ask for these details. 

Hence, there is the need for an application which the cashier (/frontdesk employee) can use to track purchases and cat information. Storing all this data on just one local machine can be unreliable (due to potential hardware failure or security breach), so it’s beneficial to have a cloud server that stores all the relevant data, along with a web service that can fetch or modify this data. The frontdesk employee computer can be connected to the internet so that it communicates with this web service, sending HTTP requests and receiving HTTP responses that communicate the necessary data and actions.

This is the problem we hope to tackle, in particular by creating the web service that would be hosted on a cloud server. The scope of our project will not include the frontend POS (point of sale) client-side application that the employees would use to interact with this web service.

## Stakeholders

Visiting customers, potential cat adopters, frontdesk employees, and the cafe owner.

## Functional Requirements

Note: ‘client’ hereafter refers to the frontdesk computer that makes requests to our web service

The web service will:
- Provide the client a particular cat’s stored details, given the cat’s ID by client
- Provide the client a list of all existing cats
- Receive (from client) and store details of donations made by customers
- Receive (from client) and store details of cats rescued and added to cafe
- Review and accept/reject requests (from client) to adopt a cat; remove cat data if successful
- Receive (from client) and store details of transactions made at the cafe
- Recall details of transactions made, given the transaction ID by client

## Use Case Description

The client can fetch the list of all existing cats, particularly their names and IDs.
If a customer asks for more info about a particular cat, the client can fetch all the specific details for that particular cat using its ID.
If the customer wants to adopt the cat, the client can request an adoption for that client, which will get approved if the cat is adoptable.
Customers can choose to donate to the cafe’s funds.
Customers can place orders (known as transactions) that contain multiple items like foods, drinks, products (merch/toys).

## List Of Resources

| Resource | Description |
| :---: | :--- |
| Cafe         | cafe’s information like name, address, donations, transactions, and availability of drinks, food, and cats |
| Cat          | provides a list of cats with their info (name, breed, age, adoptability, ...). It also allows customers to adopt cats. |
| Products     | list of products available for purchase, including cat toys and merch |
| Customer     | information about customer like name, email, phone number, membership status |
| Transactions | information about transaction like timestamp, items, qty.s, total and customer ID |
| Drinks       | drinks options and the prices associated with it |
| Food         | food options and the prices associated with it |

## List of End Points

| Endpoint URL | HTTP Method | Request Body | Expected Response | Error Status
| :---: | :---: | :---: | :---: | :---: |
| api/cat/<string>         | GET                      |TBA..| Body: JSON representation of cat info , Status: 200 OK          | 404 for not found cat with given ID |
| api/cats                 | GET                      || Body: JSON array of cat info          , Status: 200 OK          | |
| api/donate               | POST                     || Body: Confirmation message, Status: 201 Created                 | |
| api/cat                  | PUT (after rescue)       || Body: JSON representation of cat info, Status: 201 created      | |
| api/cat                  | DELETE (after adoption)  || Body: Confirmation message                                      | |
| api/transactions          | POST (new transaction)   || Body: receipt for transaction, Status: 201 Created              | |
| api/transactions/\<string\> | GET (recall transaction) || Body: receipt for transaction, Status: 200 OK                   | 404 for not found transaction with given ID |
| api/transactions/ | GET (recall transactions in date range) | date range | Body: transactions in given range, Status: 200 OK                   | |

## UML Diagrams
https://lucid.app/lucidchart/e911c24f-67c7-4dc6-ae56-0fa3b6845f79/edit?viewport_loc=-11%2C-11%2C1365%2C613%2C0_0&invitationId=inv_bc88ed82-1500-4f1f-9d53-81b338255736 
