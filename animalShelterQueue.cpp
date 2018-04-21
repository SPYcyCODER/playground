#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct animal{
	string name;
	animal(string str){
		name=str;
	}
	string getName(){	
		return name;
	}
};

class myShelter{
private:
	queue<animal*> myQ;
public:
	void enqueue(string animalName){
		myQ.push(new animal(animalName));
	}
	void dequeueAny(){
		myQ.pop();
	}
	
	void deQueueDogOrCat(string animalName){
		if(myQ.front()->getName() == animalName)
			myQ.pop();
		else{
			queue<animal*> tmp;
			while(!myQ.empty() && myQ.front()->getName() != animalName){
				tmp.push(myQ.front());
				myQ.pop();
			}
			if(myQ.empty()){
				cout<<animalName<<" is not available..\n";
			}else{
				myQ.pop();
			}	
				while(!myQ.empty()){
					tmp.push(myQ.front());
					myQ.pop();
				}
			while(!tmp.empty()){
				myQ.push(tmp.front());
				tmp.pop();
			}
		}
	}
	void print(){
		queue<animal*> q=myQ;
		while(!q.empty()){
			cout<<q.front()->getName()<<" ";
			q.pop();
		}
		cout<<endl;
	}
};
int main(){
myShelter msObj;
msObj.enqueue("DOG");
msObj.enqueue("CAT");
msObj.enqueue("CAT");
msObj.enqueue("DOG");
msObj.print();
msObj.dequeueAny();
msObj.print();
msObj.deQueueDogOrCat("DOG");
msObj.print();
}
