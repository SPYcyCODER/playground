#include <iostream>
using namespace std;

class base{
public:
	base(){cout<<"default base constructor...\n";}
	base(int x){cout<<"base parameterised constructor...\n";}
};
class derive:public base{
const int v;
public:
	//derive(){cout<<"default derive constructor...\n";}
	derive(int val):v(val) {cout<<"derive parameterised constructor..\n";}
//int y;
};
class Base{
public:
	Base(){func();cout<<"BASE CALLED\n";}
	int x;	
	int getValue(){ return x;}
	void func(){x=35; cout<<"func from Base()\n";};
};
class Base2:public Base{
public:
	Base2(){cout<<"base 2 called\n";}
	void func(){ cout<<"func from Base2()\n";}
};
class A{ int arr[10];};
class B:virtual public A{};
class C:public A{};
class D:public B,public C{};
class E{int x;virtual void func(){}};
int myFun(){
static int val=125;
cout<<"SINDIDE val : "<<val<<endl;
return val;
}
int main(){
int val=myFun();
val+=5;
val=myFun();
cout<<val<<endl;
cout<<sizeof(E)<<" "<<sizeof(E*)<<endl;
}
