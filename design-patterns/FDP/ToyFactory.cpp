#include <iostream>
using std::cout;
using std::endl;
#include "object.cpp"

class ToyFactory{
ToyFactory(){}
public:
	static Toy* createToy(int type){
		Toy *toy=NULL;
		switch(type){
			case 1: toy=new Car; break;
			case 2: toy=new Bike;break;
			case 3: toy=new Plane;break;
			default:cout<<"invalid toy type"<<endl; return NULL;
		}
		toy->prepareParts();
		toy->combineParts();
		toy->assembleParts();
		toy->applyLabel();
		return toy;
	}
};
