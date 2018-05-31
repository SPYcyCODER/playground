//
//  main.cpp
//  in-order.successor-CTCI4.6
//
//  Created by Phanindra Saggurthi on 31/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
struct BSTNode{
    int data;
    BSTNode *left,*right,*parent;
    BSTNode(int val){
        data=val;
        left=right=parent=NULL;
    }
};
BSTNode* insert(BSTNode* root,int val){
    if(!root)
        return new BSTNode(val);
    if(val < root->data){
        root->left=insert(root->left, val);
        root->left->parent=root;
    }
    else if(val > root->data){
        root->right=insert(root->right, val);
        root->right->parent=root;
    }
    return root;
}
void inOrder(BSTNode* root){
    if(!root)
        return;
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
}
void inOrderSuccessor(BSTNode* root,BSTNode*& out,int val){
    if(!root || out)
        return;
    inOrderSuccessor(root->left,out,val);
    if(root->data == val){
        if(root->right){
            root=root->right;
            if(root->left){
                while(root->left)
                    root=root->left;
                out=root;
                return;
            }else{
                out=root;
                return;
            }
        }else{
            BSTNode* pt=root->parent;
            while(pt != NULL && root == pt->right){
                root=pt;
                pt=pt->parent;
            }
            out=pt;
            return;
        }
    }
    //std::cout<<root->data<<" ";
    inOrderSuccessor(root->right,out,val);
}
int main(void) {
    BSTNode* root=NULL;
    root=insert(root, 20);
    root=insert(root, 22);
    root=insert(root, 8);
    root=insert(root, 4);
    root=insert(root, 12);
    root=insert(root, 10);
    root=insert(root, 14);
    inOrder(root);
    std::cout<<std::endl;
    BSTNode* out=NULL;
    inOrderSuccessor(root, out, 10);
    if(out)
        std::cout<<"SUCCESSOR IS : "<<out->data<<std::endl;
    else
        std::cout<<"SUCCESSOR IS EMPTY\n";
    return 0;
}

