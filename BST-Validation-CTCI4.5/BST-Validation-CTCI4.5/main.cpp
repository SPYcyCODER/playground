//
//  main.cpp
//  BST-Validation-CTCI4.5
//
//  Created by Phanindra Saggurthi on 30/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
struct BSTNode{
    int data;
    BSTNode *left,*right;
    BSTNode(int val){
        data=val;
        left=right=NULL;
    }
};
BSTNode* insert(BSTNode* root,int val){
    if(!root)
        return new BSTNode(val);
    if(val < root->data)
        root->left=insert(root->left, val);
    else if(val > root->data)
        root->right=insert(root->right, val);
    return root;
}

bool validateHelper(BSTNode* root,int minVal,int maxVal){
    if(!root)
        return true;
    if(root->data < minVal || root->data > maxVal)
        return false;
    return validateHelper(root->left, minVal, root->data-1) && validateHelper(root->right, root->data+1, maxVal);
}
bool validateBST(BSTNode* root){
    return validateHelper(root, INT_MIN, INT_MAX);
}
int main(int argc, const char * argv[]) {
    BSTNode* root=NULL;
    root=insert(root, 9);
    root=insert(root, 5);
    root=insert(root, 15);
    root=insert(root, 3);
    root=insert(root, 7);
    root=insert(root, 11);
    root=insert(root, 19);
    //root->left->right->data=21;
    bool validFlag=validateBST(root);
    if(validFlag)
        std::cout<<"BST is valid\n";
    else
        std::cout<<"BST is invalid\n";
    return 0;
}
