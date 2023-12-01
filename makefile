all: CatCafeAPI

CatCafeAPI: CatCafeAPI.o Cat.o Cafe.o Customer.o Food.o Drink.o Consumable.o ResourceAPI.o 
	g++ -lpthread -Wall CatCafeAPI.o Cat.o Cafe.o Customer.o Food.o Drink.o Consumable.o ResourceAPI.o -o CatCafeAPI

CatCafeAPI.o: CatCafeAPI.cpp Cafe.h Cat.h Customer.h Food.h Drink.h Consumable.h ResourceAPI.h FileIO.h FileIO.cpp
	g++ -Wall -c CatCafeAPI.cpp 

Cat.o: Cat.cpp Cat.h
	g++ -Wall -c Cat.cpp 

Cafe.o: Cafe.cpp Cafe.h
	g++ -Wall -c Cafe.cpp 

Customer.o: Customer.cpp Customer.h
	g++ -Wall -c Customer.cpp 

Food.o: Food.cpp Food.h Consumable.h
	g++ -Wall -c Food.cpp 

Drink.o: Drink.cpp Drink.h Consumable.h
	g++ -Wall -c Drink.cpp 

ResourceAPI.o: ResourceAPI.cpp ResourceAPI.h Cat.h Cafe.h Customer.h Food.h Drink.h Consumable.h
	g++ -Wall -c ResourceAPI.cpp 

static-analysis:
	cppcheck *.cpp

clean:
	rm -f *.o CatCafeAPI

clear-data:
	rm -f *.json