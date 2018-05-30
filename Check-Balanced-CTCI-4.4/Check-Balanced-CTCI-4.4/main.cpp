//
//  main.cpp
//  Check-Balanced-CTCI-4.4
//
//  Created by Phanindra Saggurthi on 30/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>

//
//  main.cpp
//  list-of-depths-CTCI-4.3
//
//  Created by Phanindra Saggurthi on 30/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// Create linked list of all the nodes at each level

#include <iostream>
struct bTreeNode{
    int val;
    bTreeNode *left,*right;
    bTreeNode(int value){
        val=value;
        left=right=NULL;
    }
};
int height(bTreeNode* root){
    if(!root)
        return 0;
    return 1+std::max(height(root->left),height(root->right));
}

bool isBalanced(bTreeNode* root){
    if(!root)
        return true;
    int lh=height(root->left);
    int rh=height(root->right);
    
    if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}
int main(int argc, const char * argv[]) {
    bTreeNode* root=new bTreeNode(1);
    root->left=new bTreeNode(2);
    root->right=new bTreeNode(3);
    root->left->left=new bTreeNode(4);
    root->left->right=new bTreeNode(5);
    root->right->left=new bTreeNode(6);
    root->right->right=new bTreeNode(7);
    root->right->right->left=new bTreeNode(8);
   // root->right->right->left->right=new bTreeNode(9);
    bool balanceFlag=isBalanced(root);
    if(balanceFlag)
        std::cout<<"Tree is balanced\n";
    else
        std::cout<<"Tree is unbalanced\n";
    return 0;
}
