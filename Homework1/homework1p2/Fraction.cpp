// Aashir Shukla, 917460238
#include "Fraction.h"
#include <iostream>
using namespace std;

Fraction::Fraction(int a, int b) { // constructor with two variables
	this -> a = a; 
	this -> b = b; 
	reduce(); 
}

Fraction::Fraction() { // constructor in case no variable is passed
	a = 1; 
	b = 1; 
}

Fraction& Fraction::operator=(const Fraction& rhs) { // overloading '=' operator to set fraction to any other fraction by using '='
	if(&rhs == this) // if passed fraction is equal to the variable being modified, no point modifying it
		return *this; 
	a = rhs.a; // set both values
	b = rhs.b; 
	return *this;  
}

ostream& operator << (ostream& os, const Fraction& v) { // overloading '<<' operator
	if(v.b == 1) { // to avoid outputting 2/1, for example
		os << v.a; 
	}
	else if(v.b == -1) { // to avoid outputting 2/-1, or -2/-1, etc. 
		os << -v.a; 
	}
	else if(v.b < 0) { // reset the negative denominator to positive, and change numerator to opposite sign
		os << -v.a << "/" << -v.b; 
	}
	else { // if none of the above conditions are true, just output fraction as a / b
		os << v.a << "/" << v.b; 
	} 
	return os; 
}

istream& operator >> (istream& is, Fraction &v) { // overloading '>>' operator to take input from is stream
	char slash = 0; 
	is >> v.a >> slash >> v.b; // input in the form of a / b, cin ignores whitespaces
	if(v.b == 0) { // catching the error
		throw invalid_argument("zero denominator"); 
	}

	return is; 
}

Fraction& Fraction::operator + (const Fraction& x) { // overloading '+' operator to add fractions 'this' and x - the second operand
	int num = a; 
	int dom = b; 

	// just using standard fraction addition procedure then calling reduce 

	b = dom * x.b; 
	a = num * x.b + x.a * dom; 
	reduce();
	return (*this);  
} 

Fraction& Fraction::operator - (const Fraction& x) { // overloading '-' operator to add fractions 'this' and x - the second operand
	int num = a; 
	int dom = b; // set to avoid using modified value of b in defining a

	// just using standard fraction subtraction procedure then calling reduce 

	b = dom * x.b;
	a = num * x.b - x.a * dom; 
	reduce();
	return (*this); 
} 

void Fraction::reduce() { // reduce by dividing numerator and denominator by gcd 
	int div = gcd(a, b); 
	a = a/div; 
	b = b/div; 
}

int Fraction::gcd(int a, int b) { // implemented euclid's recursive version
	if(a == 0)
		return b; 
	return gcd(b%a, a); 
}

int Fraction::getNum() const { // gives public access to numerator
	return a; 
}

int Fraction::getDen() const { // gives public access to denominator
	return b; 
}

