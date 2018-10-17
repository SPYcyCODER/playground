//
//  FactoryPattern.cpp
//  CreationalDesignPatterns
//
//  Created by Phanindra Saggurthi on 12/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Coffee{
public:
    Coffee(){
        
    }
    virtual void  makeCoffee(){}
};
class Espresso:public Coffee{
public:
    Espresso(){
        cout<<"Making Espresso...\n";
    }
    void makeCoffee(){
        cout<<"Creating espresso\n";
    }
};

class latte:public Coffee{
public:
    latte(){
        cout<<"Making Latte\n";
    }
    void makeCoffee(){
        cout<<"Creating latte\n";
    }
};

class coffeeMaker{
private:
    Coffee* _cfObj;
public:
    Coffee* getCoffee(){
        int choice;
        cout<<"Choose\n1.Espresso\n2.Latte\n";
        cin>>choice;
        switch(choice){
            case 1: return new Espresso;break;
            case 2: return new latte;break;
            default: return nullptr;
        }
        return nullptr;
    }
};

int main(void){
    Coffee* cup;
    coffeeMaker cmkObj;
    cup=cmkObj.getCoffee();
    cup->makeCoffee();
}
