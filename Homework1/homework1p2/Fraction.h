// Aashir Shukla, 917460238
#include <iostream>
#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
	public: 
	Fraction& operator=(const Fraction& rhs); 
	int getNum() const; 
	int getDen() const; 
	Fraction(int a, int b); 
	Fraction(); 
	friend std::ostream& operator << (std::ostream& os, const Fraction& v); 
	friend std::istream& operator >> (std::istream& is, Fraction& v); 
	Fraction& operator + (const Fraction& x); 
	Fraction& operator - (const Fraction& x); 

	private: 
	int a, b; 
	int gcd(int a, int b); 
	void reduce(); 
}; 

#endif