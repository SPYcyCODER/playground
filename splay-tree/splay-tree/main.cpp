//
//  main.cpp
//  splay-tree
//
//  Created by Phanindra Saggurthi on 29/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
};

node* newNode(int key){
    node* nd=(node*)malloc(sizeof(node*));
    nd->data=key;
    nd->left=nd->right=NULL;
    return nd;
}

//gpt is grand-parent and pt is parent
node* rightRotate(node* gpt){
    node* pt=gpt->left;
    gpt->left=pt->right;
    pt->right=gpt;
    return pt;
}

node* leftRotate(node* gpt){
    node* pt=gpt->right;
    gpt->right=pt->left;
    pt->left=gpt;
    return pt;
}

node* splay(node* root, int key){
    if(!root || root->data == key)
        return root;
    //splaying in left part
    if(key < root->data){
        if(!root->left)
            return root;
        if(key < root->left->data){ //Zig-Zig
            root->left->left=splay(root->left->left,key);
            root=rightRotate(root);
        }else if(key > root->left->data){ //Zig-Zag
            root->left->right=splay(root->left->right,key);
            if(root->left->right)
                root->left=leftRotate(root->left);
        }
        return (root->left == NULL)?root:rightRotate(root);
    }
    
    //if key lies in right part
    if(!root->right)
        return root;
    if(key < root->right->data){ // Zag-Zig
        root->right->left=splay(root->right->left,key);
        if(root->right->left)
            root->right=rightRotate(root->right);
    }else if(key > root->right->data){
        root->right->right=splay(root->right->right, key);
        root=leftRotate(root);
    }
    return (root->right == NULL) ? root : leftRotate(root);
}

node* insert(node* root, int key){
    if(!root)
        return newNode(key);
    root=splay(root, key);
    node* nd=newNode(key);
    if(key < root->data){
        nd->right=root;
        nd->left=root->left;
        root->left=NULL;
    }else if(key > root->data){
        nd->left=root;
        nd->right=root->right;
        root->right=NULL;
    }
    return nd;
}
node* search(node* root,int key){
    return splay(root, key);
}
void preOrder(node* rt){
    if(!rt)
        return;
    cout<<rt->data<<" ";
    preOrder(rt->left);
    preOrder(rt->right);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    node* root=NULL;
    root=insert(root,100);
    root=insert(root,50);
    root=insert(root,75);
    preOrder(root);
    cout<<endl;
    node* srch=search(root,50);
    if(srch){
        cout<<"After splaying :\n";
        preOrder(srch);
        cout<<endl;
    }else{
        cout<<" Value not found\n";
    }
    return 0;
}
