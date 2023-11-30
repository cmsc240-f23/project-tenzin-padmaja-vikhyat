FranchiseAPI: FranchiseAPI.cpp ResourceAPI.h Cat.h ResourceAPI.cpp
	g++ -lpthread FranchiseAPI.cpp ResourceAPI.cpp -o FranchiseAPI

clean:
	rm -f FranchiseAPI