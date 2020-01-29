# Aashir Shukla, 917460238
all: calculator.o useFraction.o Fraction.o
	g++ -Wall -o calculator calculator.o Fraction.o 
	g++ -Wall -o useFraction useFraction.o Fraction.o

Fraction.o: 
	g++ -c Fraction.cpp  

calculator.o: 
	g++ -c calculator.cpp 

useFraction.o: 
	g++ -c useFraction.cpp 

clean: 
	rm *.o calculator useFraction
