
#include <iostream>
using namespace std;

class Number{
    int x;
    int y;
public:
    Number(int val1,int val2):x(val1),y(val2){}
    int& getX(){ cout<<x<<endl;return x;}
    int& getY(){cout<<y<<endl;return y;}
    void print(){cout<<x<<y<<endl;}
};
int main(int argc, const char * argv[]) {
    Number n(1,2);
    int x=n.getX()=35;
    int y=n.getY()=45;
    n.print();
    cout<<Number()<<endl;
}
