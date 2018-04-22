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
void printList(Node* head){
	Node *n = head;
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
}
int findNFromLast(Node *head, int n){
	if(head == NULL || n<1)	return -1;
	Node *p1=head,*p2=head;
	while(n-->1){
		if(p2==NULL)	return -1;
		p2 = p2->next;
	}	
	while(p2->next!=NULL){
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1->data;
}
int main(){
	Node *head = new Node(1);
	head->appendToTail(6);
	head->appendToTail(2);
	head->appendToTail(3);
	head->appendToTail(4);
	head->appendToTail(7);
	head->appendToTail(5);
	head->appendToTail(3);
	head->appendToTail(6);
	head->appendToTail(2);
	head->appendToTail(7);
	printList(head);
	cout << findNFromLast(head,5) << endl;
	return 0;
}