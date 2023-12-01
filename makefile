FranchiseAPI: FranchiseAPI.cpp ResourceAPI.cpp ResourceAPI.h Cat.h FileIO.h
	g++ -lpthread FranchiseAPI.cpp ResourceAPI.cpp -o FranchiseAPI 

clean:
	rm -f FranchiseAPI