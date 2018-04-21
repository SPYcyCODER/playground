#include <iostream>
#include <stack>
using namespace std;

class myStack{
private:
	stack<int> stk,tmp;
public:
	void push(int elem){
		if(stk.empty()){
			stk.push(elem);
		}else if(stk.top()<elem){
			while(!stk.empty() && stk.top() < elem){
				tmp.push(stk.top());
				stk.pop();
			}
			stk.push(elem);
			while(!tmp.empty()){
				stk.push(tmp.top());
				tmp.pop();
			}
		}else{
			stk.push(elem);
		}
	}
	bool isEmpty(){
		return stk.empty();
	}
	void pop(){
		stk.pop();
	}
	int top(){
		return stk.top();
	}
	void print(){
		stack<int> t=stk;
		while(!t.empty()){
			cout<<t.top()<<" ";
			t.pop();
		}
		cout<<endl;
	}
};
int main(){
	myStack mst;
	mst.push(4);
	mst.push(1);
	mst.push(3);
	mst.push(2);
	cout<<mst.top()<<endl;
	mst.print();
}
