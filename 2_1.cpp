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
Node* removeDups(Node* head){
	Node *n = head;
	unordered_set<int> count;
	count.insert(n->data);
	while(n->next!=NULL){
		if(count.count(n->next->data)==1){
			n->next=n->next->next;
		}else{
			count.insert(n->next->data);
			n = n->next;
		}
	}
	return head;
}
void printList(Node* head){
	Node *n = head;
	while(n!=NULL){
		cout << n->data << " ";
		n = n->next;
	} 
	cout << endl;
}
Node* noExtraSpace(Node* head){
	if(head == NULL || head->next == NULL)	return head;
	Node *current,*last,*runner;
	current=head;
	last = head;
	runner = current->next;
	while(current->next != NULL){
		last = current;
		runner = current->next;
		while(runner!=NULL){
			if(current->data == runner->data){
				last->next = runner->next;
				runner = last->next;
			}else{
				runner = runner->next;
				last = last->next;
			}
		}
		if(current->next!=NULL)
			current = current->next;
		else 
			break;
	}
	return head;
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
	head = removeDups(head);
	printList(head);

	head->appendToTail(7);
	head->appendToTail(5);
	head->appendToTail(3);
	head->appendToTail(6);
	head->appendToTail(2);
	head->appendToTail(7);

	printList(head);
	head = noExtraSpace(head);
	printList(head);
	return 0;
}