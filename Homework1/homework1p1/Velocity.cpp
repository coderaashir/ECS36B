// Aashir Shukla, 917460238
#include "Velocity.h" // defines the member functions in the class provided in Velocity.h
#include <iostream>
using namespace std;

Velocity::Velocity() { // constructor
	v = 0; 
}
void Velocity::accelerate(int dv) { // defined as instructed
	if(v+dv > 65)
		set(65); 
	else if(v+dv < -5)
		set(-5);
	else  
		set(v+dv); 
}
int Velocity::get() { 
	return v; 
}
void Velocity::print() {
	cout << "velocity: " << v << endl; 
}
void Velocity::set(int v) {
	this -> v = v; 
}
 
