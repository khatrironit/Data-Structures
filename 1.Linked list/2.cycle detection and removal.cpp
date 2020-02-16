#include<iostream>
using namespace std;

struct node{
	int data;
	node* next;

	node(int d){
		data = d;
		next = NULL;
	}
};
bool detect_cycle(node* head){//runner technique or we can also maintain a visited variable.
	node* fast = head;
	node* slow = head;

	while(fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(slow == fast)
			return true;
	}
	return false;
}
void remove_cycle(node* &head){
	node* fast = head;
	node* slow = head;
	node* prev = NULL;

	while(fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow)
			break;
	}

	if(fast == slow){//cycle exists
		slow = head;
		while(fast!=slow){
			prev = fast;
			fast = fast->next;
			slow = slow->next;
		}
		prev->next = NULL;
	}
	return ;
}
void printlist(node* head){
	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	return;
}

int main(){
	node* head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = head->next->next;
	cout<<endl<<detect_cycle(head);
	remove_cycle(head);
	cout<<endl<<detect_cycle(head)<<endl;
	printlist(head);

	return 0;
}