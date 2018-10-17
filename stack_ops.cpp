#include <iostream>
using namespace std;

template<typename T>
class myStack{
private:
	int size,max;
	T* elems;
public:
	myStack(int sz){
		size=0;
		max=sz;
		elems=new T[sz];
	}
	~myStack(){
		delete[] elems;
	}
	bool isEmpty(){
		return size==0;
	}
	T peek(){
		if(isEmpty()){
			cout<<"Stack is empty..\n";
			return -1;
		}
		return elems[size-1];
	}
	T pop(){
		if(size < 0 ){
			cout<<"Stack is empty...\n";
			return -1;
		}
		T elem=peek();
		size--;
		return elem;
	}

	void push(T elem){
		if(size >= max){
			cout<<"Stack overflow...\n";
			return;
		}
		elems[size++]=elem;
	}
	void print(){
		for(int ind=0;ind<size;ind++){
			cout<<*(elems+ind)<<" ";
		}
		cout<<endl;
	}
};

int main(){
myStack<int> mst(5);
mst.push(3);
mst.push(2);
mst.push(1);
mst.push(7);
mst.push(9);
mst.push(19);
mst.print();
cout<<mst.pop()<<" eliminated from stack...\n";
mst.push(25);
mst.print();
cout<<mst.pop()<<" eliminated from stack...\n";
cout<<mst.pop()<<" eliminated from stack...\n";
cout<<mst.pop()<<" eliminated from stack...\n";
cout<<mst.pop()<<" eliminated from stack...\n";
cout<<mst.pop()<<" eliminated from stack...\n";
cout<<mst.pop()<<" eliminated from stack...\n";
}
