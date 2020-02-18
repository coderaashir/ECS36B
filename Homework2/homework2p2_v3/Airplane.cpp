#include "Airplane.h"
using namespace std; 

Airplane::Airplane(int n): maxContainers(n) {numContainers = 0; }

int Airplane::maxLoad(void) {
	return maxContainers; 
}

int Airplane::currentLoad(void) {
	return numContainers; 
}

bool Airplane::addContainers(int n) {
	if(numContainers + n > maxContainers)
		return false; 
	numContainers += n; 
	return true;  
}