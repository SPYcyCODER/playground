#include <iostream>
using namespace std;


class base{
private:
	//const int x;
	int _x;
public:
	base(int _x):_x(_x){
		//_x=_x;
	}
	void print(){
		cout<<_x<<endl;
	}
};
int main(){
	base b(5);
	b.print();
	return 0;
}
