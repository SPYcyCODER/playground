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

void buildOrderHelper(node* curNode,unordered_set<node*>& visited,unordered_set<node*>& curSet,stack<node*>& out,bool& loopCheck){
    if(loopCheck)
        return;
    for(auto dep:curNode->children){
        if(curSet.find(dep) != curSet.end()){
            loopCheck=true;
            break;
        }
        if(visited.find(dep) != visited.end())
            continue;
        curSet.insert(dep);
        buildOrderHelper(dep, visited,curSet, out,loopCheck);
    }
    if(visited.find(curNode) == visited.end() && !loopCheck){
        visited.insert(curNode);
        out.push(curNode);
    }
}
void getBuildOrderWithLoopCheck(unordered_set<node*>& nodes,unordered_set<node*>& visited,stack<node*>& out){
    for(auto _node:nodes){
        if(visited.find(_node) != visited.end())
            continue;
        unordered_set<node*> curSet;
        bool loopCheck=false;
        buildOrderHelper(_node, visited,curSet, out,loopCheck);
        if(loopCheck){
            std::cout<<"ERROR : LOOP EXISTS in Graph\n";
            while(!out.empty())
                out.pop();
            break;
        }
    }
}
int main(){
    node* root=new node('a');
    node* two=new node('b');
    node* thr=new node('c');
    node* fur=new node('d');
    node* fiv=new node('e');
    node* six=new node('f');
    node* gee=new node('g');
    root->children.push_back(six);
    two->children.push_back(six);
    thr->children.push_back(fur);
    fur->children.push_back(root);
    fur->children.push_back(six);
    gee->children.push_back(fiv);
    unordered_set<node*> _uset;
    _uset.insert(root);
    _uset.insert(two);
    _uset.insert(thr);
    _uset.insert(fur);
    _uset.insert(fiv);
    _uset.insert(six);
    _uset.insert(gee);
    stack<node*> out;
    unordered_set<node*> visited;
    getBuildOrder(_uset, visited, out);
    //Printing the order in reverese form
    while(!out.empty()){
        std::cout<<out.top()->data<<" ";
        out.pop();
    }
    std::cout<<endl;
    node* one=new node('1');
    node* too=new node('2');
    node* tree=new node('3');
    node* fawr=new node('4');
    node* faayv=new node('5');
    node* seecs=new node('6');
    one->children.push_back(too);
    one->children.push_back(tree);
    one->children.push_back(fawr);
    too->children.push_back(tree);
    fawr->children.push_back(faayv);
    faayv->children.push_back(seecs);
    //seecs->children.push_back(fawr);
    unordered_set<node*> _uset_l;
    _uset_l.insert(one);
    _uset_l.insert(too);
    _uset_l.insert(tree);
    _uset_l.insert(fawr);
    _uset_l.insert(faayv);
    _uset_l.insert(seecs);
    stack<node*> out_l;
    unordered_set<node*> visited_l;
    getBuildOrderWithLoopCheck(_uset_l,visited_l,out_l);
    while(!out_l.empty()){
        std::cout<<out_l.top()->data<<" ";
        out_l.pop();
    }
    std::cout<<endl;
}
