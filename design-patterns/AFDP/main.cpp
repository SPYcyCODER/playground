#include <iostream>
using namespace std;

void add(int& x){
	x++;
}

void add(int&& x){
	x++;
}
void pass_ref(int*& y){
	y=new int;
}
void pass_val(int* y){
	y=new int;
}
class test{
public:
	test(char*){}
	test(int n=0,int n1=1,int n2=5){}
};
class base{
public:
	int _x;
	base(){}
	base(int x):_x(x){}
};
class derived:public base{
int y;
public:
	derived(){}
	derived(int x,int yVal):y(yVal),base(x){}
};
int main(){
	test t4(5);
	int x=25;
	add(x);
	cout<<x<<endl;
	add(10);
	cout<<x<<endl;

	int* p1=NULL,*p2=NULL;
	pass_val(p1);
	pass_ref(p2);
	if(!p1)
		cout<<"value fasak\n";
	if(p2){
		cout<<"Object created\n";
	}
	derived d(5,2);
	derived d2;
}
