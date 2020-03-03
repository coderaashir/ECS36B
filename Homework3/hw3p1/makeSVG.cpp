#include <iostream>
using namespace std;

int main() {
	cout << "<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>" << endl; 
	cout << "<svg width=\"700\" height=\"600\"" << endl; 
	cout << "xmlns=\"http://www.w3.org/2000/svg\">" << endl; 
	cout << "<g transform=\"matrix(1,0,0,-1,50,550)\"" << endl; 
	cout << "fill=\"white\" fill-opacity=\"0.5\" stroke=\"black\" stroke-width=\"2\">" << endl; 
	cout << "<rect fill=\"lightgrey\" x=\"0\" y=\"0\" width=\"600\" height=\"500\"/>" << endl; 

	char ch; 
	int a, b, c, d; 

	while(cin >> ch) { 
		if(ch == 'R') {
			cin >> a >> b >> c >> d; 
			cout << "<rect x=\"" << a << "\" y=\"" << b << "\" width=\"" << c << "\" height=\"" << d << "\"/>" << endl; 
		}
		else {
			cin >> a >> b >> c; 
			cout << "<circle cx=\"" << a << "\" cy=\"" << b << "\" r=\"" << c << "\"/>" << endl;
		}
	}

	cout << "</g>" << endl; 
	cout << "</svg>" << endl;  
}