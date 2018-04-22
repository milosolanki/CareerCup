#include <bits/stdc++.h>
using namespace std;
class Node{
public:
	int data;
	Node *next = NULL;
	Node(int d){	this->data = d;	}
	void appendToTail(int d){
		Node *end = new Node(d);
		Node *n = this;
		while(n->next!=NULL)	n = n->next;
		n->next = end;
	}
};
Node* SumList(Node *l1,Node *l2){
	if(l1==NULL)	return l2;
	if(l2==NULL)	return l1;
	int sum=0,carry=0,flag=0;
	Node *e1=NULL, *e2=NULL,*ans = l1;
	while(l1!=NULL && l2!=NULL){
		sum = l1->data + l2->data + carry;
		l1->data = sum%10;
		carry = sum/10;
		if(l1->next==NULL) e1 = l1;
		l1 = l1->next;
		// if(l2->next==NULL) e2 = l2;
		l2 = l2->next;
	}
	while(l1!=NULL){
		flag=1;
		sum = l1->data + carry;
		l1->data = sum%10;
		carry = sum/10;
		if(l1->next==NULL) e1 = l1;
		l1 = l1->next;
	}
	while(l2!=NULL){
		flag=2;
		sum = l2->data + carry;
		e1->next = new Node(sum%10);
		l2->data = sum%10;
		carry = sum/10;
		// if(l2->next==NULL) e2 = l2;
		l2 = l2->next;
	}
	if(carry)	e1->next = new Node(carry);
	return ans;
}
void printList(Node* head){
	Node *n = head;
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
}
int main(){
	Node *l1 = new Node(3),*l2 = new Node(5);
	l1->appendToTail(1);
	l1->appendToTail(5);
	l2->appendToTail(9);
	l2->appendToTail(2);
	cout << "List 1:\n";
	printList(l1);
	cout << "List 2:\n";
	printList(l2);
	cout << "Sum of lists:\n";
	printList(SumList(l1,NULL));
	return 0;
}