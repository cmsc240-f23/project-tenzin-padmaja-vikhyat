# Project Design Document

## Introduction

The web service will be used to operate a cat cafe where customers can buy different food,drinks, and products for themselves or for the cats, and they can also inquire about and adopt rescued cats.

## Background/Context

The web service is designed to address the interest in cat adoption and catering needs of both cat enthusiasts and potential cat owners. Additionally, it’s also meant to inform people about animal rescue and adoption. 

Cat cafes are becoming an increasingly popular type of cafe: they allow visitors to come play with cats sheltered by the cafe, eat and drink at the cafe, buy merch, and also potentially adopt the cats. These cafes process hundreds of transactions everyday, and must maintain information on all their cats, since potential adopters would ask for these details. 

Hence, there is the need for an application which the cashier (/frontdesk employee) can use to track purchases and cat information. Since storing these details on just one local machine can be risky due to potential hardware failure, it’s beneficial (and often more technologically efficient) to have a cloud server that’s running a web service that stores all the relevant data. The frontdesk employee computer can be connected to the internet so that it communicates with this web service, sending HTTP requests and receiving HTTP responses that communicate the necessary data and actions.

This is the problem we hope to tackle, in particular by designing and eventually implementing the web service that would be hosted

## Stakeholders

Visiting customers, potential cat adopters, frontdesk employees, and the cafe owner.

## Functional Requirements

The web service will contain bio data on different cats available for adoption and for cat cafe sessions. Users will be able to purchase food and drinks for themselves and for the cats. They can buy cat toys and merch and can also choose to donate to the cafe’s rescue team so they can provide for the rescued cats.

## Use Case Description

Describe all the interactions between users and the system. This can be in the form of user stories. For example, “As a customer, I want to view book reviews and ratings before purchasing, so that I can make informed decisions.”

## List Of Resources

| Resource | Description |
| :---: | :--- |
| Cafe         | cafe’s information like name, address, donations, transactions, and availability of drinks, food, and cats |
| Cat          | provides a list of cats with their info. It also allows customers to adopt cats. |
| Products     | list of products available for purchase, including cat toys and merch |
| Transactions | information about transaction like timestamp, items, qty.s and info about customer like name, email, phone number and membership |
| Drinks       | drinks options and the prices associated with it |
| Food         | food options and the prices associated with it |



## List of End Points

| Endpoint URL | HTTP Method | Expected Response | Error Status
| :---: | :---: | :---: | :---: |
| api/cat/<string>         | GET                      | Body: JSON representation of cat info , Status: 200 OK          | 404 for not found cat with given ID |
| api/cats                 | GET                      | Body: JSON array of cat info          , Status: 200 OK          | |
| api/donate               | POST                     | Body: Confirmation message, Status: 201 Created                 | |
| api/cat                  | PUT (after rescue)       | Body: JSON representation of cat info, Status: 201 created      | |
| api/cat                  | DELETE (after adoption)  | Body: Confirmation message                                      | |
| api/transaction          | POST (new transaction)   | Body: receipt for transaction, Status: 201 Created              | |
| api/transaction/<string> | GET (recall transaction) | Body: receipt for transaction, Status: 200 OK                   | 404 for not found transaction with given ID |

## UML Diagrams
https://lucid.app/lucidchart/e911c24f-67c7-4dc6-ae56-0fa3b6845f79/edit?viewport_loc=-11%2C-11%2C1365%2C613%2C0_0&invitationId=inv_bc88ed82-1500-4f1f-9d53-81b338255736 
