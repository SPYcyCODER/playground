//
//  graphs.cpp
//  smart-pointers
//
//  Created by Phanindra Saggurthi on 17/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    bool visited;
    vector<node*> children;
    node(int val){
        data=val;
        visited=false;
    }
};
/*
node* findNode(node* root, node* fnd){
    if(!root || root == fnd)
        return root;
    for(auto n:root->children){
        if(n->data == fnd->data){
            
        }
    }
    return root;
}*/
bool isRouteAvailable(node* t1,node* t2){
    if(!t1 || !t2)
        return false;
    for(auto child:t1->children){
        if(child->visited)
            continue;
        child->visited=true;
        if(child->data == t2->data){
            return true;
        }
        if(isRouteAvailable(child,t2 ))
            return true;
    }
    return false;
}
int main(){
    node* root=new node(1);
    node* two=new node(2);
    node* thr=new node(3);
    node* fur=new node(4);
    root->children.push_back(two);
    root->children.push_back(thr);
    two->children.push_back(fur);
    thr->children.push_back(two);
    fur->children.push_back(thr);
    cout<<"1 to 4 : "<<isRouteAvailable(root, fur)<<endl;
}
