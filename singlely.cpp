#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	Node *next;
	Node(int x){
		val=x;
		next=NULL;
	}
};

void print(Node *head){
	if(head==NULL)
		cout<<"empty"<<endl;
	else{
		while(head->next!=NULL){
			cout<<head->val<<endl;
			head=head->next;
		}
	}
}

void printIterative(Node *head){
	if(head==NULL)
		cout<<"empty"<<endl;
	else{
		Node *temp=head;
		while(temp!=NULL){
			cout<<temp->val<<endl;
			temp=temp->next;
		}
	}
}

void printRec(Node *head){
	if(head==NULL)
		return;
	cout<< head->val<<endl;	
	printRec(head->next);
}

Node *insertAtBegin(Node *head,int x){
	Node *temp=new Node(x);
	temp->next=head;
	return temp;
}
Node *insertAtEnd(Node *head,int x){
	Node *temp=new Node(x);
	if(head==NULL)
		return temp;
	Node *cur=head;
	while(cur->next!=NULL){
		cur=cur->next;
	}
	cur->next=temp;

	return head;
}

Node *deletehead(Node *head){
	
	if(head==NULL)
		return NULL;
	else{
		Node *temp=head->next;
		delete head;
		return temp;
	}

}

Node *delTail(Node *head){

	Node *temp=head;
	if(head==NULL)
		return NULL;
	else{
		while(temp->next!=NULL)
			temp=temp->next;
		}
		Node *r=temp;
		temp->next=NULL;
		delete r;
		return head;
}

int main()
{
	freopen("opp.txt","w",stdout);
	/*Node *head=new Node(10);
	head->next=new Node(20);
	head->next->next=new Node(30);
	head->next->next->next=new Node(40);
	head->next->next->next->next=new Node(50);
	head->next->next->next->next->next=new Node(60);*/

	//print(head);
	//printRec(head);

	/*Node *head=NULL;
	head=insertAtBegin(head,10);
	head=insertAtBegin(head,20);
	head=insertAtBegin(head,30);
	head=insertAtBegin(head,40);
	head=insertAtBegin(head,50);*/

	//printRec(head);

	Node *head=NULL;
	head=insertAtEnd(head,10);	
	head=insertAtEnd(head,20);	
	head=insertAtEnd(head,30);	
	head=insertAtEnd(head,40);	
	head=insertAtEnd(head,50);	

	/*head=deletehead(head);
	printRec(head);*/
	
	head=delTail(head);
	//printRec(head);
	printIterative(head);
	return 0;
}