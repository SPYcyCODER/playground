//
//  main.cpp
//  list-of-depths-CTCI-4.3
//
//  Created by Phanindra Saggurthi on 30/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
// Create linked list of all the nodes at each level

#include <iostream>
#include <vector>
#include <queue>
struct bTreeNode{
    int val;
    bTreeNode *left,*right;
    bTreeNode(int value){
        val=value;
        left=right=NULL;
    }
};
struct listNode{
    int data;
    listNode *next;
    listNode(int val){
        data=val;
        next=NULL;
    }
};
std::vector<listNode*> getLevelLists(bTreeNode* root){
    std::vector<listNode*> result;
    std::queue<bTreeNode*> _treeQueue;
    _treeQueue.push(root);
    while(!_treeQueue.empty()){
        auto curLevelCount=_treeQueue.size();
        listNode* levelNode=NULL,*prevNode=NULL;
        while(curLevelCount--){
            auto frntNode=_treeQueue.front();
            _treeQueue.pop();
            if(!levelNode){
                levelNode=new listNode(frntNode->val);
                prevNode=levelNode;
            }else{
                prevNode->next=new listNode(frntNode->val);
                prevNode=prevNode->next;
            }
            if(frntNode->left)
                _treeQueue.push(frntNode->left);
            if(frntNode->right)
                _treeQueue.push(frntNode->right);
        }
        result.push_back(levelNode);
    }
    return result;
}
int main(int argc, const char * argv[]) {
    bTreeNode* root=new bTreeNode(1);
    root->left=new bTreeNode(2);
    root->right=new bTreeNode(3);
    root->left->left=new bTreeNode(4);
    root->left->right=new bTreeNode(5);
    root->right->left=new bTreeNode(6);
    root->right->right=new bTreeNode(7);
    std::vector<listNode*> out=getLevelLists(root);
    for(auto node:out){
        while(node){
            std::cout<<node->data<<"->";
            node=node->next;
        }
        std::cout<<std::endl;
    }
    return 0;
}
