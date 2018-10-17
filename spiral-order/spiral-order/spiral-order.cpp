
#include <iostream>
using namespace std;

struct node{
    node *next;
    long long int val;
    node(long long int iVal):val(iVal){
        next=NULL;
    }
};
void printList(node* ls){
    node* tmp=ls;
    while(tmp){
        cout<<tmp->val<<" ";
        tmp=tmp->next;
    }
    cout<<endl;
}
void deleteNode(struct node **head_ref, int key)
{
    // Store head node
    struct node* temp = *head_ref, *prev;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->val == key)
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }
    
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->val != key)
    {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == NULL) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    free(temp);
}
int main(void){
    int N;
    cin>>N;
    node* head=NULL,*tail=NULL;
    long long int val;
    while(cin>>val){
        if(!head){
            head=new node(val);
            tail=head;
        }else{
            node* curNode=new node(val);
            tail->next=curNode;
            tail=curNode;
        }
    }
    // printList(head);
    long long int aScore=0,bScore=0;
    int pInd=0;
    
    while(N){
        int curScore=0;
        node *prevSlow=NULL;
        node* slow=head,*fast=head;
        while(slow && fast && fast->next){
            fast=fast->next->next;
            prevSlow=slow;
            slow=slow->next;
        }
        cout<<"Removing middle node : ";
        if(N%2){
            curScore=slow->val;
            cout<<slow->val<<endl;
            node* tmp=slow;
            if(prevSlow){
                prevSlow->next=slow->next;
            }else{
                slow=slow->next;
            }
            delete(tmp);
        }else{
            if(slow->val > slow->next->val){
                curScore=slow->val;
                cout<<slow->val<<endl;
                node* tmp=slow;
                if(prevSlow){
                    prevSlow->next=slow->next;
                }else{
                    slow=slow->next;
                }
                delete(tmp);
            }else{
                curScore=slow->next->val;
                cout<<slow->next->val<<endl;
                if(prevSlow){
                    prevSlow->next=slow->next;
                }else{
                    slow->next=slow->next->next;
                    delete(slow->next);
                }
            }
        }
        //deleteNode(&head,slow->val);
        printList(head);
        N--;
        if(pInd)
            bScore+=curScore;
        else
            aScore+=curScore;
        pInd=1-pInd;
    }
    if(bScore > aScore){
        cout<<"Bob"<<" "<<abs(bScore-aScore);
    }else{
        cout<<"Alex"<<" "<<abs(bScore-aScore);
    }
}
