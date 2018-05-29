//
//  main.cpp
//  red-black
//
//  Created by Phanindra Saggurthi on 28/05/18.
//  Copyright © 2018 Phanindra Saggurthi. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

enum color{RED,BLACK};
struct node{
    int data;
    bool color;
    node *left,*right,*parent;
    node(int val){
        data=val;
        left=right=parent=NULL;
    }
};
class RBTree{
private:
            node* root;
protected:
            void rotateLeft(node*&,node*&);
            void rotateRight(node*&,node*&);
            void fixViolation(node*&,node*&);
public:
            RBTree():root(NULL){}
            void insert(const int&);
            void inOrder(node*);
            void levelOrder(node*);
    node* getRoot(){
        return root;
    }
};
void RBTree::inOrder(node* root){
    if(!root)
        return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
node* BSTInsert(node* root, node* pt){
    if(!root)
        return pt;
    if(pt->data < root->data){
        root->left=BSTInsert(root->left, pt);
        root->left->parent=root;
    }else if(pt->data > root->data){
        root->right=BSTInsert(root->right, pt);
        root->right->parent=root;
    }
    return root;
}

void RBTree::levelOrder(node* root){
    if (root == NULL)
        return;
    
    std::queue<node*> q;
    q.push(root);
    
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
        
        if (temp->left != NULL)
            q.push(temp->left);
        
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

void RBTree::rotateLeft(node*& root, node*& pt){
    node* pt_right=pt->right;
    pt->right=pt_right->left;
    if (pt->parent == NULL)
        root = pt_right;
    
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    
    else
        pt->parent->right = pt_right;
    
    pt_right->left = pt;
    pt->parent = pt_right;
}
void RBTree::rotateRight(node *&root, node *&pt)
{
    node *pt_left = pt->left;
    
    pt->left = pt_left->right;
    
    if (pt->left != NULL)
        pt->left->parent = pt;
    
    pt_left->parent = pt->parent;
    
    if (pt->parent == NULL)
        root = pt_left;
    
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    
    else
        pt->parent->right = pt_left;
    
    pt_left->right = pt;
    pt->parent = pt_left;
}
void RBTree::fixViolation(node*& root, node *&pt){
    node* parent_pt=NULL;
    node* grand_parent_pt=NULL;
    
    while((pt!=root) && (pt->color != BLACK) && (pt->parent->color == RED)){
        parent_pt=pt->parent;
        grand_parent_pt=pt->parent->parent;
        //parent of pt is left child of grand parent node
        if(parent_pt == grand_parent_pt->left){
            node* uncle_pt=grand_parent_pt->right;
            if(uncle_pt && uncle_pt->color==RED){
                grand_parent_pt->color=RED;
                uncle_pt->color=BLACK;
                parent_pt->color=BLACK;
                pt=grand_parent_pt;
            }else{
                if(pt == parent_pt->right){
                    rotateLeft(root, parent_pt);
                    pt=parent_pt;
                    parent_pt=pt->parent;
                }
                
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color,grand_parent_pt->color);
                pt=parent_pt;
            }
        }else{
            node* uncle_pt=grand_parent_pt->left;
            if(uncle_pt && uncle_pt->color==RED){
                grand_parent_pt->color=RED;
                uncle_pt->color=BLACK;
                parent_pt->color=BLACK;
                pt=grand_parent_pt;
            }else{
                if(pt == parent_pt->left){
                    rotateRight(root, parent_pt);
                    pt=parent_pt;
                    parent_pt=pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color,grand_parent_pt->color);
                pt=parent_pt;
            }
        }
    }
    root->color=BLACK;
}
void RBTree::insert(const int &data)
{
    node *pt = new node(data);
    
    // Do a normal BST insert
    root = BSTInsert(root, pt);
    
    // fix Red Black Tree violations
    fixViolation(root, pt);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    RBTree tree;
    
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);
    
    cout << "Inoder Traversal of Created Tree\n";
    tree.inOrder(tree.getRoot());
    
    cout << "\n\nLevel Order Traversal of Created Tree\n";
    tree.levelOrder(tree.getRoot());
    cout<<endl;
    return 0;
}
