#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class myQueue{
private:
	stack<T> stk1,stk2;
public:
	void push(T elem){
		stk1.push(elem);
	}
	void pop(){
		if(stk2.empty()){
			while(!stk1.empty()){
				stk2.push(stk1.top());
				stk1.pop();
			}
		}
		stk2.pop();
	}	
	T front(){
		if(stk2.empty()){
                        while(!stk1.empty()){
                                stk2.push(stk1.top());
                                stk1.pop();
                        }
                }
                return stk2.top();
	}
	int size(){
		return stk1.size()+stk2.size();
	}
	void print(){
		stack<T> tmp1=stk1,tmp2=stk2;
		while(!tmp2.empty()){
			cout<<tmp2.top()<<" ";
			tmp2.pop();
		}
		if(tmp2.empty()){
			while(!tmp1.empty()){
				tmp2.push(tmp1.top());
				tmp1.pop();
			
		}
		}
		while(!tmp2.empty()){
			cout<<tmp2.top()<<" ";
			tmp2.pop();
		}
		cout<<endl;
	}
};
int main(){

myQueue<int> qObj;
qObj.push(1);
qObj.push(2);
qObj.pop();
qObj.push(3);
qObj.push(4);
qObj.print();
qObj.pop();
qObj.print();}
