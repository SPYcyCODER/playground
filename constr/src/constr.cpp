//============================================================================
// Name        : constr.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using std::cout;
class A{
public:
	explicit A(const int i){
		cout<<"call from integer\n";
	}
	A(const char *){
		cout<<"call from char *\n";
	}
};
int main() {
	A a('x');
	return 0;
}
