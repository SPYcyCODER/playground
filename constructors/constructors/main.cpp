//
//  main.cpp
//  constructors
//
//  Created by Phanindra Saggurthi on 12/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
#include <string>

class A{
public:
    A(){
        std::cout<<"Constructor call from default one\n";
    }
    A(int i){
        std::cout<<"Constructor call from integer\n";
    }
    A(std::string s){
        std::cout<<"COnstructor call from string\n";
    }
    A(const char* c){
        std::cout<<"Constructor call from char*\n";
    }
    A(char c){
        std::cout<<"Constructor call from char\n";
    }
    
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::string s="x";
    A a('x');
    A b("Phani");
    auto name="Phanindra";
    puts(name);
    return 0;
}
