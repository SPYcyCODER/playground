#include <iostream>
using namespace std;
void tp(int* x){
*x=55;
cout<<*x<<endl;
}
struct sup{
int x;
bool bt;
char c;
int d;
bool b;
};
class Base{
public:
	virtual void print(){
		cout<<"Print from Base\n";
	}
};
class derived1:public Base{
public:
	virtual void print(){
		cout<<"Print from derived\n";
	}
};
class derived2:public Base{
public:
	void print(){
		cout<<"print from derived 2\n";
	}
};
int main(){
//const_cast
	const int i1=14;
	const int* b1=&i1;
	int *d1=const_cast<int*>(b1);
	*d1=15;
	cout<<i1<<endl;
	cout<<*d1<<endl;
	tp(const_cast<int*>(b1));
	cout<<*b1<<endl;

//reinterpret_cast
	sup sObj;
	sObj.x=99;
	sObj.d=22;
	sObj.c='A';
	sObj.b=true;
	sObj.bt=false;
	int* ptr=reinterpret_cast<int*>(&sObj);
	cout<<*ptr<<endl;
	ptr++;
	bool *c=reinterpret_cast<bool*>(ptr);
	cout<<*c<<endl;
	c++;
	cout<<*ptr<<endl;
//DYNAMIC_CAST
cout<<"*****************************\n";
	derived1 dObj;
	Base* base1=dynamic_cast<Base*>(&dObj);
	base1->print();
	derived2* d2=dynamic_cast<derived2*>(base1);
	//d2->print();
}
