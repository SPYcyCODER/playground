#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class myStack{
private:
	int size,max;
	T* elems;
public:
	myStack(){}
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
	int getSize(){
		return size;
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
template<typename T>
class stackOfPlates:public myStack<T>{
private:
	vector<myStack<T>*> stks;
	int stkSize;
	int stkInd;
public:
	stackOfPlates(int sz){
		stkInd=0;
		stkSize=sz;
		stks.push_back(new myStack<T>(sz));
	}
	void push(int elem){
		if(stks[stkInd]->getSize() >= stkSize){
			stks.push_back(new myStack<T>(stkSize));
			++stkInd;
		}
		stks[stkInd]->push(elem);
	}
	T pop(){
		int curInd=stkInd;
		if(stks[stkInd]->getSize() == 1)
			--stkInd;	
		if(stkInd == -1)
			stkInd=0;
		return stks[curInd]->pop();
	}
	T popAt(int index){
		if(index > stkInd){
			cout<<"Illegal entry..\n";
			return -1;
		}
		return stks[stkInd]->pop();
	}
	~stackOfPlates(){
		for(auto stk:stks)
			delete stk;
	}
	void printStacks(){
		for(int i=0;i<stks.size();i++){
			cout<<"***"<<i<<"****\n";
			stks[i]->print();
		}
	}
};
int main(){
stackOfPlates<int> stpObj(3);
stpObj.push(1);
stpObj.push(2);
stpObj.push(3);
stpObj.popAt(0);
stpObj.push(11);
stpObj.push(22);
stpObj.push(33);
stpObj.printStacks();
stpObj.push(21);
stpObj.push(22);
stpObj.push(23);
stpObj.popAt(1);
stpObj.printStacks();
}
