#include <iostream>
using namespace std;

struct Node{
	struct Node* next;
	int val;
	Node(int v){
		next=NULL;
		val=v;
	}
};
void insert(Node** head,int value){
	if(!*head){
		*head=new Node(value);
		return;
	}

	Node* tmp=*head;
	while(tmp->next){
		tmp=tmp->next;
	}
	tmp->next=new Node(value);
}
void removeDups(Node** head,int delVal){
	Node* delNode=NULL;
	if((*head)->val == delVal){
		delNode=*head;
		*head=(*head)->next;
		delete(delNode);
		return;
	}

	Node* tmp=(*head);
	Node* prevNode=NULL;
	while(tmp){
		if(tmp->val == delVal){
			delNode=tmp;
			prevNode->next=tmp->next;
			prevNode=prevNode->next;
			tmp=prevNode;
			cout<<"::REMOVING::\n";
			delete(delNode);
		}else{
			prevNode=tmp;
			tmp=tmp->next;
		}
	}
}
void print(Node* head){
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
Node* kthNode(Node* head,int kPos){
	if(!head)
		return NULL;
	Node* prevNode=NULL;
	while(head){
		Node* nextNode=head->next;
		head->next=prevNode;
		prevNode=head;
		if(!nextNode)
			break;
		head=nextNode;
	}
	prevNode=NULL;
	int pos=1;
	while(head){
		if(pos == kPos)
			return head;
		pos++;
		Node* nextNode=head->next;
		head->next=prevNode;
		prevNode=head;
		if(!nextNode)
			break;
		head=nextNode;
	}

	return head;
}
Node* partitionList(Node* head,int xVal){
	Node* left=NULL,*root=NULL,*right=NULL,*ll=NULL,*rr=NULL;
	while(head){
		Node* nextNode=head->next;
		if(head->val < xVal){
			if(!left){
				left=head;
				ll=left;
				ll->next=NULL;
			}else{
				ll->next=head;
				ll=head;
				ll->next=NULL;
			}
		}else if(head->val == xVal){
			root=head;
			root->next=NULL;
		}else{
			if(!right){
				right=head;
				rr=right;
				rr->next=NULL;
			}else{
				rr->next=head;
				rr=head;
				rr->next=NULL;
			}
		}
		head=nextNode;
	}
	print(left);
	print(root);
	print(right);
	ll->next=root;
	root->next=right;
	return left;
}
int main(){
	Node* head=NULL;
	insert(&head,3);
	insert(&head,5);
	insert(&head,8);
	insert(&head,5);
	insert(&head,10);
	insert(&head,2);
	insert(&head,1);
	print(head);
	//cout<<"Deleting 2 : "<<endl;
	//removeDups(&head,2);
	//print(head);
	//cout<<kthNode(head,3)->val<<endl;
	print(partitionList(head,5));
}
