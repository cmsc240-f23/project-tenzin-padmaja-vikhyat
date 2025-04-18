# Project Design Document

## Introduction

The web service will be used to operate a cat cafe where customers can spend time with cats, get food/drinks for themselves or for the cats, buy merch/toys, and also adopt rescued cats.

## Background/Context

The web service is designed to address the interest in cat adoption and catering needs of both cat enthusiasts and potential cat owners. Additionally, it’s also meant to inform people about animal rescue and adoption. 

Cat cafes are becoming an increasingly popular type of cafe: they allow visitors to come play with cats sheltered by the cafe, eat and drink at the cafe, buy merch, and also potentially adopt the cats. These cafes process hundreds of transactions everyday, and must maintain information on all their cats, since potential adopters would ask for these details. 

Hence, there is the need for an application which the cashier (/frontdesk employee) can use to track purchases and cat information. Storing all this data on just one local machine can be unreliable (due to potential hardware failure or security breach), so it’s beneficial to have a cloud server that stores all the relevant data, along with a web service that can fetch or modify this data. The frontdesk employee computer can be connected to the internet so that it communicates with this web service, sending HTTP requests and receiving HTTP responses that communicate the necessary data and actions.

This is the problem we hope to tackle, in particular by creating the web service that would be hosted on a cloud server. The scope of our project will not include the frontend POS (point of sale) client-side application that the employees would use to interact with this web service.

## Stakeholders

- **Visiting Customers**: These are people who use the API to spend time with the cats, purchase food or drinks and feed the cats too.
- **Potential Cat Adopters**: These are people who use the API to adopt a cat from the cafe depending on whether the cat is available for adoption
- **Front Desk Employees**: These are people who use the API to manage the flow of customers and cat adoption.


## Functional Requirements

Note: ‘client’ hereafter refers to the frontdesk computer that makes requests to our web service

The web service will:
- Provide the client a particular cat’s stored details, given the cat’s ID by client
- Provide the client a list of all existing cats
- Receive (from client) and store details of donations made by customers
- Receive (from client) and store details of cats rescued and added to cafe
- Review and accept/reject requests (from client) to adopt a cat; remove cat data from the cafe
- Receive (from client) and store details of transactions made at the cafe
- Recall details of transactions made, given the transaction ID by client

## Use Case Description

The client can fetch the list of all existing cats/customers/foods/drinks, particularly their names and IDs.
If the client wants more info about a particular cat/customer/food/drink, the client can fetch all the specific details for that particular resource using its ID.
If a customer at the cafe has 'adopted' a cat, the client can request an adoption by deleting the cat from the list of cats in the cafe. 
Similarly, the client can delete information on any customer/food/drink.
Information on any cat/customer/food/drink can be updated.
A customer can filter food and drinks based on whether or not they are consumable by cats.

## List Of Resources

| Resource | Description |
| :---: | :--- |
| Cafe         | cafe’s information like name, address, email |
| Cat          | provides a list of cats with their info (name, breed, age, adoptability, ...). It also allows customers to adopt cats. |
| Customer     | information about customer like name, email, phone number, membership status |
| Drink       | drinks options with quantity and the prices associated with it |
| Food         | food options with quantity and the prices associated with it |

## List of End Points

| Relevant Resource | Endpoint URL | HTTP Method | Request Body | Expected Response | Error Status
| :---: | :---: | :---: | :---: | :---: | :---: |
| Cats | api/cats                    | POST      | JSON representation of cat info | Status: 201 created, Body: JSON representation of cat info | 400 Bad Request (body JSON did not match the resource structure) |
| Cats | api/cats                    | GET                      |                                 | Status: 200 OK, Body: JSON representation of all cats' info | |
| Cats | api/cats/\<string\>         | GET                      |                                 | Status: 200 OK, Body: JSON representation of cat info | 404 for not found cat with given ID |
| Cats | api/cats/\<string\>         | PUT                      | JSON representation of cat info | Status: 200 OK, Body: JSON representation of cat info | Status: 404 Cat with given ID not found OR 400 Bad Request (body JSON did not match the resource structure) |
| Cats | api/cats/\<string\>         | DELETE                   |                                 | Status: 200 OK          | 404 for not found cat with given ID |
| Customers | api/customers                    | POST     | JSON representation of customer info | Status: 201 created, Body: JSON representation of customer info | 400 Bad Request (body JSON did not match the resource structure) |
| Customers | api/customers                    | GET                      |                                 | Status: 200 OK, Body: JSON representation of all customers' info | |
| Customers | api/customers/\<string\>         | GET                      |                                 | Status: 200 OK, Body: JSON representation of customer info | 404 for not found customer with given ID |
| Customers | api/customers/\<string\>         | PUT                      | JSON representation of customer info | Status: 200 OK, Body: JSON representation of customer info | Status: 404 customer with given ID not found OR 400 Bad Request (body JSON did not match the resource structure) |
| Customers | api/customers/\<string\>         | DELETE                   |                                 | Status: 200 OK          | 404 for not found customer with given ID |
| Foods | api/foods                    | POST (after rescue)      | JSON representation of food info | Status: 201 created, Body: JSON representation of food info | 400 Bad Request (body JSON did not match the resource structure) |
| Foods | api/foods                    | GET                      |                                 | Status: 200 OK, Body: JSON representation of all foods' info | |
| Foods | api/foods/\<string\>         | GET                      |                                 | Status: 200 OK, Body: JSON representation of food info | 404 for not found food with given ID |
| Foods | api/foods/\<string\>         | PUT                      | JSON representation of food info | Status: 200 OK, Body: JSON representation of food info | Status: 404 food with given ID not found OR 400 Bad Request (body JSON did not match the resource structure) |
| Foods | api/foods/\<string\>         | DELETE                   |                                 | Status: 200 OK          | 404 for not found food with given ID |
| Foods | api/foods?catConsumable=<true/false> | GET                      |  | Status: 200 OK, Body: JSON representation of all cat-eligible foods | |
| Drinks | api/drinks                    | POST (after rescue)      | JSON representation of drink info | Status: 201 created, Body: JSON representation of drink info | 400 Bad Request (body JSON did not match the resource structure) |
| Drinks | api/drinks                    | GET                      |                                 | Status: 200 OK, Body: JSON representation of all drinks' info | |
| Drinks | api/drinks/\<string\>         | GET                      |                                 | Status: 200 OK, Body: JSON representation of drink info | 404 for not found drink with given ID |
| Drinks | api/drinks/\<string\>         | PUT                      | JSON representation of drink info | Status: 200 OK, Body: JSON representation of drink info | Status: 404 drink with given ID not found OR 400 Bad Request (body JSON did not match the resource structure) |
| Drinks | api/drinks/\<string\>         | DELETE                   |                                 | Status: 200 OK          | 404 for not found drink with given ID |
| Drinks | api/drinks?catConsumable=<true/false> | GET                      |  | Status: 200 OK, Body: JSON representation of all cat-eligible drinks | |
| Cafe | api/cafe                    | GET                      |                                 | Status: 200 OK, Body: JSON representation of cafe info | |
| Cafe | api/cafe                    | PUT                      | JSON representation of cafe info | Status: 200 OK, Body: JSON representation of cafe info | Status: 400 Bad Request (body JSON did not match the resource structure) |




## UML Diagrams
https://lucid.app/lucidchart/e911c24f-67c7-4dc6-ae56-0fa3b6845f79/edit?viewport_loc=-11%2C-11%2C1365%2C613%2C0_0&invitationId=inv_bc88ed82-1500-4f1f-9d53-81b338255736 
![Cat Cafe API UML Diagram](UML_Diagram.png)