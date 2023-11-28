all: musicStoreAPI static-analysis run-unit-tests 

musicStoreAPI: musicStoreAPI.o Genre.o Artist.o Album.o Record.o CompactDisc.o GenericAPI.o 
	g++ -lpthread musicStoreAPI.o Genre.o Artist.o Album.o Record.o CompactDisc.o GenericAPI.o -o musicStoreAPI

musicStoreAPI.o: musicStoreAPI.cpp CompactDisc.h Record.h Artist.h Genre.h GenericAPI.h persistence.h
	g++ -Wall -c musicStoreAPI.cpp 

Record.o: Record.cpp Record.h
	g++ -Wall -c Record.cpp 

CompactDisc.o: CompactDisc.cpp CompactDisc.h
	g++ -Wall -c CompactDisc.cpp 

Album.o: Album.cpp Album.h
	g++ -Wall -c Album.cpp 

Arist.o: Artist.cpp Artist.h
	g++ -Wall -c Artist.cpp 

Genre.o: Genre.cpp Genre.h
	g++ -Wall -c Genre.cpp 

GenericAPI.o: GenericAPI.cpp GenericAPI.h Genre.h Artist.h Record.h
	g++ -Wall -c GenericAPI.cpp 

GenericAPITest: GenericAPITest.cpp GenericAPI.o Artist.o Album.o Record.o CompactDisc.o Genre.o
	g++ -lpthread GenericAPITest.cpp GenericAPI.o Artist.o Album.o Record.o CompactDisc.o Genre.o -o GenericAPITest

persistenceTest: persistenceTest.cpp persistence.h Genre.o
	g++ -lpthread persistenceTest.cpp Genre.o -o persistenceTest

GenreTest: GenreTest.cpp Genre.cpp Genre.h Genre.o
	g++ -lpthread GenreTest.cpp Genre.o -o GenreTest

run-unit-tests: GenericAPITest persistenceTest
	./GenericAPITest    ;\
	./persistenceTest	;\
	./GenreTest

static-analysis:
	cppcheck *.cpp

clean:
	rm -f *.o musicStoreAPI GenericAPITest persistenceTest GenreTest