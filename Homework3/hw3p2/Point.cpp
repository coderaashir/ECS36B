#include <iostream>
#include "Point.h" 
using namespace std;

Point Point::operator+(const Point& rhs) const {
	Point ret = Point(x + rhs.x, y + rhs.y); 
	return ret; 
}

Point Point::operator-(const Point& rhs) const {
	Point ret = Point(x - rhs.x, y - rhs.y); 
	return ret; 
}

ostream& operator<<(ostream& os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")"; 
	return os; 
}

istream& operator>>(std::istream& is, Point& p) {
	is >> p.x >> p.y; 
	return is; 
}