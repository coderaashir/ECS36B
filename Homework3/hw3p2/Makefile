# Aashir Shukla, 917460238	
all: Domain.o checkpack.o Point.o Shape.o testShape.o testPoint.o 
	g++ -Wall -o checkpack checkpack.o Shape.o Point.o Domain.o
	g++ -Wall -o testShape testShape.o Shape.o Point.o 
	g++ -Wall -o testPoint Point.o testPoint.o 

checkpack.o: 
	g++ -Wall -c checkpack.cpp 

Point.o: 
	g++ -Wall -c Point.cpp

Shape.o: 
	g++ -Wall -c Shape.cpp

Domain.o: 
	g++ -Wall -c Domain.cpp 

testPoint.o: 
	g++ -Wall -c testPoint.cpp 

testShape.o: 
	g++ -Wall -c testShape.cpp 

clean: 
	rm *.o checkpack testShape testPoint
