//
//  main.cpp
//  avl-tree
//
//  Created by Phanindra Saggurthi on 28/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// AVL Tree ops


#include <iostream>
using namespace std;

struct node{
    int data;
    node *left,*right;
    int height;
    node(int val):data(val),left(NULL),right(NULL),height(1){}
};
 node* newNode(int key)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return node;
}
int height(node* root){
    if(!root)
        return 0;
    return root->height;
}

int max(int val1,int val2){
    return (val1>val2)?val1:val2;
}
node* rightRotate(node* root){
    node* tmpRoot=root->left;
    node* tmpRight=tmpRoot->right;
    tmpRoot->right=root;
    root->left=tmpRight;
    root->height=max(height(root->left),height(root->right))+1;
    tmpRoot->height=max(height(tmpRoot->left),height(tmpRoot->right))+1;
    return tmpRoot;
}

node* leftRotate(node* root){
    node* tmpRoot=root->right;
    node* tmpLeft=tmpRoot->left;
    tmpRoot->left=root;
    root->right=tmpLeft;
    root->height=max(height(root->left),height(root->right))+1;
    tmpRoot->height=max(height(tmpRoot->left),height(tmpRoot->right))+1;
    return tmpRoot;
}

int getBalance(node* root){
    if(!root)
        return 0;
    return height(root->left)-height(root->right);
}

node* avlInsert(node* root,int val){
    if(!root){
        return (newNode(val));
    }
    
    if(val < root->data){
        root->left=avlInsert(root->left, val);
    }else if(val > root->data){
        root->right=avlInsert(root->right,val);
    }else
        return root;
    root->height=max(height(root->left),height(root->right))+1;
    int balance=getBalance(root);
    //cout<<" For "<<val<< "balance is : "<<balance<<endl;
    //left-left case
    if(balance > 1 && val < root->data){
        return rightRotate(root);
    }else if(balance > 1 && val > root->data){ // Left - Right Case
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }else if(balance < -1 && val < root->data){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }else if(balance < -1 && val > root->data){
        return leftRotate(root);
    }
    return root;
}
void preOrder(node* root){
    if(root){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
node* getMinValueNode(node* tmp){
     node* root=tmp;
    while(root->left)
        root=root->left;
    return root;
}

node* deleteNode(node* root, int findVal){
    if(!root)
        return root;
    if(findVal < root->data)
        root->left=deleteNode(root->left,findVal);
    else if(findVal > root->data)
        root->right=deleteNode(root->right,findVal);
    else{
        if(!root->left || !root->right){
            node* tmp=root->left?root->left:root->right;
            if(!tmp){
                tmp=root;
                root=NULL;
            }else{
                *root=*tmp;
            }
            free(tmp);
        }else{
            node* tmp=getMinValueNode(root->right);
            root->data=tmp->data;
            root->right=deleteNode(root->right,tmp->data);
        }
    }
    if(!root)
        return root;
    root->height=max(height(root->left),height(root->right))+1;
    
    int balance=getBalance(root);
    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }else if(balance > 1 &&getBalance(root->left) < 0){ // Left - Right Case
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }else if(balance < -1 && getBalance(root->right) > 0){
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }else if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }
    return root;
}
node * search(node* root,int findVal){
    if(!root)
        return NULL;
    if(root->data > findVal)
        return search(root->left,findVal);
    else if(root->data < findVal)
        return search(root->right,findVal);
    else if(root->data == findVal)
        return root;
    return NULL;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    node* root=NULL;
    root=avlInsert(root, 10);
    root=avlInsert(root, 20);
    root=avlInsert(root, 30);
    root=avlInsert(root, 40);
    root=avlInsert(root, 50);
    root=avlInsert(root, 25);
    root=avlInsert(root, 45);
    root=avlInsert(root, 47);
    
    cout<<"Pre order traversal : ";
    preOrder(root);
    cout<<endl;
    root=deleteNode(root, 47);
    cout<<"Post deletion : ";
    preOrder(root);
    cout<<endl;
    node* tmp=search(root,15);
    if(tmp)
        cout<<"element found..\n";
    else
        cout<<"element not found...\n";
    return 0;
}
