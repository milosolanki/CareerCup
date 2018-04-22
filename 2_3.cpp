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
void deleteNode(Node* c){
	if(c == NULL || c->next==NULL)	return;
	c->data = c->next->data;
	c->next = c->next->next;
	return;
}
int main(){
	//delet node from middle of the list
	Node *head = new Node(1),*temp = head;
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
	for(int i=0;i<5;i++)	temp  = temp->next;
	printList(head);
	cout << "Deleting the node with value " << temp->data << endl;
	deleteNode(temp);
	printList(head);
	return 0;
}