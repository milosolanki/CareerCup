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
int main(){
	unordered_set<int> count;
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
	Node *n = head;
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
	n = head;
	count.insert(n->data);
	while(n->next!=NULL){
		if(count.count(n->next->data)==1){
			n->next=n->next->next;
		}else{
			count.insert(n->next->data);
			n = n->next;
		}
	}
	n = head;
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
	return 0;
}