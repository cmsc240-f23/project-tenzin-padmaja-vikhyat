all: FranchiseAPI

FranchiseAPI: FranchiseAPI.o Cat.o Cafe.o Customer.o ResourceAPI.o 
	g++ -lpthread -Wall FranchiseAPI.o Cat.o Cafe.o Customer.o ResourceAPI.o -o FranchiseAPI

FranchiseAPI.o: FranchiseAPI.cpp Cafe.h Cat.h Customer.h ResourceAPI.h FileIO.h FileIO.cpp
	g++ -Wall -c FranchiseAPI.cpp 

Cat.o: Cat.cpp Cat.h
	g++ -Wall -c Cat.cpp 

Cafe.o: Cafe.cpp Cafe.h
	g++ -Wall -c Cafe.cpp 

Customer.o: Customer.cpp Customer.h
	g++ -Wall -c Customer.cpp 

ResourceAPI.o: ResourceAPI.cpp ResourceAPI.h Cat.h Cafe.h Customer.h
	g++ -Wall -c ResourceAPI.cpp 

static-analysis:
	cppcheck *.cpp

clean:
	rm -f *.o FranchiseAPI

clear-data:
	rm -f *.json
	
# # FranchiseAPI: FranchiseAPI.cpp ResourceAPI.cpp ResourceAPI.h Cat.h FileIO.h Cafe.h
# # 	g++ -lpthread FranchiseAPI.cpp ResourceAPI.cpp -o FranchiseAPI 
# # 
# # clean:
# # 	rm -f FranchiseAPI
# all: FranchiseAPI

# FranchiseAPI: FranchiseAPI.o Cat.o Cafe.o Customer.o Food.o Drink.o Consumable.o ResourceAPI.o 
# 	g++ -lpthread -Wall FranchiseAPI.o Cat.o Cafe.o Customer.o ResourceAPI.o Food.o Drink.o Consumable.o -o FranchiseAPI

# FranchiseAPI.o: FranchiseAPI.cpp Cafe.h Cat.h Customer.h Food.h Drink.h ResourceAPI.h FileIO.h Consumable.h
# 	g++ -Wall -c FranchiseAPI.cpp 

# Cat.o: Cat.cpp Cat.h
# 	g++ -Wall -c Cat.cpp 

# Cafe.o: Cafe.cpp Cafe.h
# 	g++ -Wall -c Cafe.cpp 

# Customer.o: Customer.cpp Customer.h
# 	g++ -Wall -c Customer.cpp 

# Consumable.o: Consumable.cpp Consumable.h
# 	g++ -Wall -c Consumable.cpp 

# Food.o: Food.cpp Food.h
# 	g++ -Wall -c Food.cpp 

# Drink.o: Drink.cpp Drink.h
# 	g++ -Wall -c Drink.cpp 

# ResourceAPI.o: ResourceAPI.cpp ResourceAPI.h Cat.h Cafe.h Customer.h Food.h Drink.h Consumable.h
# 	g++ -Wall -c ResourceAPI.cpp 

# static-analysis:
# 	cppcheck *.cpp

# clean:
# 	rm -f *.o FranchiseAPI