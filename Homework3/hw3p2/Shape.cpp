#include "Shape.h"
#include <iostream>
using namespace std;

Rectangle::~Rectangle(){}  
Circle::~Circle(){} 

bool Shape::overlaps(const Shape& s) const {
	const Rectangle *p = dynamic_cast<const Rectangle*>(&s); 
	const Rectangle *z = dynamic_cast<const Rectangle*>(this);  

	if(p != 0) {
		if(z != 0) {
			return p->overlaps(*z);
		}
		else {
			const Circle *b = dynamic_cast<const Circle*>(this); 
			return p->overlaps(*b); 
		}
	}

	else {
		if(z != 0) {
			const Circle *b = dynamic_cast<const Circle*> (&s);
			return  z -> overlaps(*b); 
		}
		else {
			const Circle *a = dynamic_cast<const Circle*> (&s); 
			const Circle *b = dynamic_cast<const Circle*> (this);
			return a->overlaps(*b); 
		}
	}
}

bool Shape::overlaps(const Circle& r) const {
	const Rectangle *z = dynamic_cast<const Rectangle*>(this); 
	if(z != 0) {
		return z -> overlaps(r); 
	}
	else {
		const Circle* b = dynamic_cast<const Circle*>(this); 
		return b -> overlaps(r); 
	}
}

bool Shape::overlaps(const Rectangle& r) const {
	const Rectangle *z = dynamic_cast<const Rectangle*>(this); 
	if(z != 0) {
		return z -> overlaps(r); 
	}
	else {
		const Circle* b = dynamic_cast<const Circle*>(this); 
		return b -> overlaps(r); 
	}
}

bool Shape::fits_in(const Rectangle& r) const { 
	const Rectangle *z = dynamic_cast<const Rectangle*>(this); 
	if(z != 0) {
		return z -> fits_in(r); 
	}
	else {
		const Circle* b = dynamic_cast<const Circle*>(this); 
		return b -> fits_in(r); 
	}
}

void Shape::draw(void) const { 
	const Rectangle *z = dynamic_cast<const Rectangle*>(this);
	if(z != 0) {
		z -> draw(); 
	}
	else {
		const Circle* b = dynamic_cast<const Circle*>(this); 
		b -> draw(); 
	}
}

/////////

bool Rectangle::overlaps(const Shape& r) const {
	const Rectangle *p = dynamic_cast<const Rectangle*>(&r); 

	if(p != 0) {
		return overlaps(*p); 
	}

	else {
		const Circle* b = dynamic_cast<const Circle*>(&r); 
		return overlaps(*b);  
	}
}

bool Rectangle::overlaps(const Circle& r) const {
	int Xn = min (max(r.center.x, position.x), position.x + width); 
	int Yn = min (max(r.center.y, position.y), position.y + height);  
	Point newPoint = Point(Xn - r.center.x, Yn-r.center.y); 	
	int d = newPoint.norm2(); 
	if(d >= r.radius * r.radius)
		return false; 
	return true; 
}

bool Rectangle::overlaps(const Rectangle& r) const {
	if(position.x >= r.position.x + r.width || r.position.x >= position.x + width) 
		return false; 

	if(position.y >= r.position.y + r.height || r.position.y >= position.y + height)
		return false; 

	return true; 
}

bool Rectangle::fits_in(const Rectangle& r) const {
	if(r.position.x <= position.x && position.x + width <= r.position.x + r.width) {
		if(r.position.y <= position.y && position.y + height <= r.position.y + r.height) {
			return true;
		}
	}
	return false;
}

void Rectangle::draw(void) const {
	cout << "<rect x=\"" << position.x << "\" y=\"" << position.y << "\" width=\"" << width << "\" height=\"" << height << "\"/>" << endl;
}

///////////

bool Circle::overlaps(const Shape& s) const {
	const Rectangle *p = dynamic_cast<const Rectangle*>(&s); 

	if(p != 0) {
		return overlaps(*p); 
	}

	else {
		const Circle* b = dynamic_cast<const Circle*>(&s); 
		return overlaps(*b);  
	}
}

bool Circle::overlaps(const Circle& r) const {
	Point z = Point(center.x-r.center.x, center.y-r.center.y); 
	if(z.norm2() < (r.radius + radius) * (r.radius+radius))
		return true; 
	return false; 
}

bool Circle::overlaps(const Rectangle& r) const {
	const Circle newCircle = Circle(center, radius); 
	return r.overlaps(newCircle); 
}

bool Circle::fits_in(const Rectangle& r) const {
	if(center.x - radius >= r.position.x && center.y + radius <= r.position.y+r.height) {
		if(center.x + radius <= r.position.x + r.width && center.y >= r.position.y)
			return true; 
	}
	return false; 
}

void Circle::draw(void) const {
	cout << "<circle cx=\"" << center.x << "\" cy=\"" << center.y << "\" r=\"" << radius << "\"/>" << endl;
}

