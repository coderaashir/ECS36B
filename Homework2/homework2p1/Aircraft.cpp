#include "Aircraft.h"
#include <iostream>
using namespace std;

Aircraft::Aircraft(int n, string name_str): numEng(n), nm(name_str) {}

A380::A380(string name_str): Aircraft(4, name_str) {hrs = new int; }

B737::B737(string name_str): Aircraft(2, name_str) {hrs = new int; }

Aircraft* Aircraft::makeAircraft(char ch, std::string name_str) {
	if(ch == 'A') {
		return new A380(name_str); 
	}
	else if(ch == 'B') {
		return new B737(name_str); 
	}
	else {
		return NULL; 
	}
}

const string Aircraft::type(void) const {
	if(numEng == 2) {
		return "Boeing 737"; 
	} 
	else {
		return "Airbus A380"; 
	}
}

const string A380::type(void) const {
	return "Airbus A380"; 
}

const string B737::type(void) const {
	return "Boeing A380"; 
}

const int Aircraft::maxHours(void) const {
	if(numEng == 2)
		return 500; 
	else 
		return 750; 
}

const int A380::maxHours(void) const {
	return 750; 
}


const int B737::maxHours(void) const {
	return 500; 
}

const string Aircraft::name(void) const {
	return nm; 
}

int Aircraft::numEngines(void) const {
	return numEng; 
}

void Aircraft::setHours(int i, int h) {
	hrs[i] = h;  
}

void Aircraft::print(void) const {
	cout << "Aircraft: " << nm << " type: " << (numEng == 2 ? "Boeing B737": "Airbus A380") << " has " << numEng << " engines" << endl;
	
	for(int i=1; i<=numEng; i++)
		cout << "engine " << i << ": " << hrs[i] << " hours" << endl; 
}

void Aircraft::printSchedule(void) const {
	cout << "Maintenance schedule for " << nm << endl; 

	for(int i=1; i<=numEng; i++) {
		if(((numEng == 2? 500: 750) - hrs[i]) <= 0)
			cout << "engine " << i << ": maintenance due now!!" << endl; 
		else 
			cout << "engine " << i << ": maintenance due in " << ((numEng == 2? 500: 750) - hrs[i]) << " hours" << endl; 
	}
}

Aircraft::~Aircraft(){} 