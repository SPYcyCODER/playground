#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include "ToyFactory.cpp"

int main(){
	int type;
	while(1){
		cout<<endl<<"Enter type or zero to exit..\n";
		cin>>type;
		if(!type)
			break;
		Toy* toyPtr=ToyFactory::createToy(type);
		if(toyPtr){
			toyPtr->showProduct();
			delete toyPtr;
		}
	}
	cout<<"Exit..\n";
}
