#include <iostream>
using namespace std;

template<typename T>
void print(const T val){
	static int value=10;
	cout<<++value<<endl;
}
int main(){
	int v1;
	v1=(1,2,3);
	print(1);
	print("Hello");
	print(11);
	print(9.8);
	cout<<v1<<endl;
return 0;
}
