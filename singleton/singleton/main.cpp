//
//  main.cpp
//  singleton
//
//  Created by Phanindra Saggurthi on 15/10/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
class singleton{
    
};
void ptrCheck(int* &ptr){
    ptr += 45;
    std::cout<<"INSIDE : "<<*ptr<<std::endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a=25;
    int *ptr=&a;
    ptrCheck(ptr);
    std::cout<<a<<std::endl;
    return 0;
}
