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
Node* findLoopStart(Node* head){
	Node *p1=head,*p2=head;
	while(p2->next!=NULL){
		p1 = p1->next;
		p2 = p2->next->next;
		if(p1==p2)	break;
	}
	if(p2==NULL)	return NULL;
	p1 = head;
	while(p1!=p2){
		p1=p1->next;
		p2=p2->next;
	}
	return p1;
}
int main(){
	Node *head = new Node(1),*tmp = head,*mid = head;
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
	for(int i=0;i<5;i++)	mid = mid->next;
	while(tmp->next!=NULL)	tmp = tmp->next;
	tmp->next = mid;
	Node * ans = findLoopStart(head);
	if(ans!=NULL)
		cout <<  ans->data << endl;
	return 0;
}