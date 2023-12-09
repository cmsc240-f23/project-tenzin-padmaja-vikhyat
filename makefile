all: CatCafeAPI run-unit-tests static-analysis 

CatCafeAPI: CatCafeAPI.o Cat.o Cafe.o Customer.o Food.o Drink.o Consumable.o ResourceAPI.o 
	g++ -lpthread -Wall CatCafeAPI.o Cat.o Cafe.o Customer.o Food.o Drink.o Consumable.o ResourceAPI.o -o CatCafeAPI

CatCafeAPI.o: CatCafeAPI.cpp Cafe.h Cat.h Customer.h Food.h Drink.h Consumable.h ResourceAPI.h FileIO.h FileIO.cpp
	g++ -Wall -c CatCafeAPI.cpp 

Cat.o: Cat.cpp Cat.h
	g++ -Wall -c Cat.cpp 

Cafe.o: Cafe.cpp Cafe.h
	g++ -Wall -c Cafe.cpp 

Customer.o: Customer.cpp Consumable.cpp Customer.h
	g++ -Wall -c Customer.cpp 

Food.o: Food.cpp Food.h Consumable.cpp Consumable.h 
	g++ -Wall -c Food.cpp 

Drink.o: Drink.cpp Drink.h Consumable.h
	g++ -Wall -c Drink.cpp 

ResourceAPI.o: ResourceAPI.cpp ResourceAPI.h Cat.h Cafe.h Customer.h Food.h Drink.h
	g++ -Wall -c ResourceAPI.cpp 

ResourceAPITest: ResourceAPITest.cpp ResourceAPI.o Cat.o Cafe.o Customer.o Consumable.o Food.o Drink.o
	g++ -lpthread ResourceAPITest.cpp ResourceAPI.o Cat.o Cafe.o Customer.o Consumable.o Food.o Drink.o -o ResourceAPITest

FileIOTest: FileIOTest.cpp FileIO.h Cat.o
	g++ -lpthread -Wall FileIOTest.cpp Cat.o -o FileIOTest

CafeTest: CafeTest.cpp Cafe.o
	g++ -lpthread -Wall CafeTest.cpp Cafe.o -o CafeTest
	
CatTest: CatTest.cpp Cat.o
	g++ -lpthread -Wall CatTest.cpp Cat.o -o CatTest

CustomerTest: CustomerTest.cpp Customer.o
	g++ -lpthread -Wall CustomerTest.cpp Customer.o -o CustomerTest

FoodTest: FoodTest.cpp Food.o
	g++ -lpthread -Wall FoodTest.cpp Food.o Consumable.o -o FoodTest

DrinkTest: DrinkTest.cpp Drink.o
	g++ -lpthread -Wall DrinkTest.cpp Drink.o Consumable.o -o DrinkTest

run-unit-tests: ResourceAPITest FileIOTest CafeTest CatTest CustomerTest FoodTest DrinkTest 
	./ResourceAPITest ;\
	./FileIOTest ;\
	./CafeTest ;\
	./CatTest ;\
	./CustomerTest ;\
	./FoodTest ;\
	./DrinkTest 

static-analysis:
	cppcheck *.cpp

clean:
	rm -f *.o CatCafeAPI NewFileIOTest CatTest CustomerTest FoodTest DrinkTest ResourceAPITest

clear-data:
	rm -f *.json