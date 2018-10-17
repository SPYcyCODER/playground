//
//  main.cpp
//  inorder-no-recursion
//
//  Created by Phanindra Saggurthi on 04/07/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
struct node{
    node *parent,*left,*right;
    int data;
    node(int dt){
        data=dt;
        parent=left=right=NULL;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
