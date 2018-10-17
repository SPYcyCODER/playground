#include <iostream>
using namespace std;

class Point{
int x,y;
public:
	Point(){}
	Point(int xVal,int yVal):x(xVal),y(yVal){}
	/*int operator+(Point& p2){
		return p2.x+this->x+p2.y+this->y;
	}*/
	friend int operator+(Point& p1,Point& p2);
};
int operator+(Point& p1,Point& p2){
	return p1.x+p1.y+p2.x+p2.y;
}
class P{};
class p:private P{};
int main(){
	Point p1(2,3),p2(4,5);
	cout<<p1+p2<<endl;
    char c;
    //int* p=(int*)&c;
    //int* p=static_cast<int*>(&c);
    //*p=534234;
    p _p;
    P* pObj=(P*)&_p;;
    P* _pObj=static_cast<P*>(&_p);
    
return 0;
}
