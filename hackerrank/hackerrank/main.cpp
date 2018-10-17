//
//  main.cpp
//  hackerrank
//
//  Created by Phanindra Saggurthi on 22/08/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
using namespace std;
struct A{
    A(){
        throw 2;
    }
};
struct B{
    B()
    try{
        A a;
    }catch(int i){
        cout<<i;
    }
};
int main(int argc, const char * argv[]) {
    //B b;
    return 0;
    int i ,&j=i;
    cout<<decltype(i)<<endl;
}
