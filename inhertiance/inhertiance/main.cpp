//
//  main.cpp
//  inhertiance
//
//  Created by Phanindra Saggurthi on 12/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
using std::cout;
class A{
private:
    int iVal;
public:
    A(){
        cout<<"Constr A\n";
    }
    A(int val):iVal(val){}
    ~A(){
        cout<<"Destr A\n";
    }
    void print(){
        cout<< " from A\n";
    }
protected:
    void printProtect(){
        cout<<"From protected A\n";
    }
};
class B:protected A{
public:
    B(){
        cout<<"Constr B\n";
    }
    ~B(){
        cout<<"Destr B\n";
    }
    void printProtectB(){
        cout<<"from B,calling A's protect\n";
        printProtect();
    }
};
int main(int argc, const char * argv[]) {
    B bObj;
    //bObj.print();
    bObj.printProtectB();
    return 0;
}
