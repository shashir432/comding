#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data=data;
			next=NULL;
		}		
};

void print(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

Node* takeinput(){
	int data;
	cin>>data;
	Node* head=NULL;
	while(data!=-1){
		Node* newNode=new Node(data);
		if(head==NULL){
			head=newNode;
		}
		else{
			Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newNode;
		}
		cin>>data;
	}
	return head;
}

Node* takeinput_better(){
	int data;
	cin>>data;
	Node* head=NULL;
	Node* tail=NULL;
	while(data!=-1){
		Node* temp=new Node(data);
		if(head==NULL){
			head=temp;
			tail=temp;
		}
		else{
			tail->next=temp;
			tail=temp;
		}
		cin>>data;
	}
	return head;
}

int main(){
//	Node *n1=new Node(10);
//	Node *n2=new Node(20);
//	Node *n3=new Node(30);
//	Node *n4=new Node(40);
//	Node *head=n1;
//	n1->next=n2;
//	n2->next=n3;
//	n3->next=n4;
    //Node* head=takeinput();
    list<int> l; //doubly stl list
    l.push_front(10); 
    l.push_back(20);
    l.push_back(30);
    l.push_front(40);
    //l.pop_back();
    //l.pop_front();
    int s=l.size();
    int top=l.front(); 
    int bck=l.back();
    for(int i=0;i<s;i++){
    	cout<<l.back()<<" ";
    	l.pop_back();
	}
	for(int i=0;i<s;i++){
    	cout<<l.front()<<" ";
    	l.pop_front();
	}
	//print(head);
}

