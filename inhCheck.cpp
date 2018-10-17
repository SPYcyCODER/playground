#include <iostream>
#include <typeinfo>
using namespace std;

class test{
	int *ptr;
public:
	test(){
		cout<<"Default constructor...\n";
	}
	test(const test& tmp){
		ptr=new int;
		val=tmp.val;
		*ptr=*tmp.ptr;
		cout<<"COPY constructor...\n";
	}
	test& operator=(const test& tmp){
		cout<<"Operator assignment..\n";
		ptr=new int;
		val=tmp.val;
		*ptr=*(tmp.ptr);	
		return *this;
	}
	~test(){
		cout<<"Destructor..\n";
	}
protected:
	int val;
};
class t:public test{};
int main(){
	test t1;
	test t2(t1);
	test t3;
	t3=t1;
	t tObj;
	cout<<tObj.val<<endl;
return 0;
}
