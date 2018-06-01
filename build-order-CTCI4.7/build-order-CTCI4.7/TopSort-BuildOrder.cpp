//
//  main.cpp
//  build-order-CTCI4.7
//
//  Created by Phanindra Saggurthi on 31/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//  Topological Sort

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

struct node{
    char data;
    bool visited;
    vector<node*> children;
    node(char val){
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

void buildOrderHelper(node* curNode,unordered_set<node*>& visited,stack<node*>& out){
    for(auto dep:curNode->children){
        if(visited.find(dep) != visited.end())
            continue;
        buildOrderHelper(dep, visited, out);
    }
    if(visited.find(curNode) == visited.end()){
        visited.insert(curNode);
        out.push(curNode);
    }
}
void getBuildOrder(unordered_set<node*>& nodes,unordered_set<node*>& visited,stack<node*>& out){
    for(auto _node:nodes){
        if(visited.find(_node) != visited.end())
            continue;
        buildOrderHelper(_node, visited, out);
    }
}

int main(){
    node* root=new node('a');
    node* two=new node('b');
    node* thr=new node('c');
    node* fur=new node('d');
    node* fiv=new node('e');
    node* six=new node('f');
    root->children.push_back(six);
    two->children.push_back(six);
    thr->children.push_back(fur);
    fur->children.push_back(root);
    fur->children.push_back(six);
    unordered_set<node*> _uset;
    _uset.insert(root);
    _uset.insert(two);
    _uset.insert(thr);
    _uset.insert(fur);
    _uset.insert(fiv);
    _uset.insert(six);
    stack<node*> out;
    unordered_set<node*> visited;
    getBuildOrder(_uset, visited, out);
    //Printing the order in reverese form
    while(!out.empty()){
        std::cout<<out.top()->data<<" ";
        out.pop();
    }
    std::cout<<endl;
}
