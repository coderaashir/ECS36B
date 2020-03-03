#include "Domain.h"
#include <iostream>
using namespace std;

Domain::Domain() {
	sizex = 500; 
	sizey = 600; 
}

Domain::~Domain(){} 

void Domain::addShape(const Shape* p) {
	s.push_back(p); 
}

void Domain::draw() {
	cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl; 
	cout << "<svg width=\"700\" height=\"600\"" << endl; 
	cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl; 
	cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl; 
	cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl; 
	cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl; 

	for(int i=0; i<s.size(); i++) 
		s[i] -> draw(); 

	cout << "</g>" << endl; 
	cout << "<g transform=\"matrix(1,0,0,1,50,590)\"" << endl; 
	cout << " font-family=\"Arial\" font-size=\"32\">" << endl; 
	cout << "<text x=\"0\" y=\"0\">"; 

	Point P = Point(0,0); 
	Rectangle x = Rectangle (P, 600, 500); 

	for(int i=0; i<s.size(); i++) {
		if(!s[i]->fits_in(x)) { 
			cout << "does not fit</text>" << endl; 
			cout << "</g>" << endl; 
			cout << "</svg>" << endl;
			return; 
		}
	}

	for(int i=0; i<s.size()-1; i++) {
		for(int j=i+1; j<s.size(); j++) {
			if(s[i]->overlaps(*s[j])) {
				cout << "overlap</text>" << endl; 
				cout << "</g>" << endl; 
				cout << "</svg>" << endl;
				return;  
			}
		}
	}

	cout << "ok</text>" << endl; 
	cout << "</g>" << endl; 
	cout << "</svg>" << endl; 
}