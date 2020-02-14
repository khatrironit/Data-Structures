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
void createlist(node* &head){
	int data;
	cout<<"Enter data for list or -1 to exit";
	cin>>data;
	if(data == -1)
		return;
	head = new node(data);
	node* tail = head;
	cin>>data;
	while(data!=-1){
		node* temp = new node(data);
		tail->next = temp;
		tail = temp;
		cin>>data;
	}
	return;
}
int length_of_list(node* head){
	int counter = 0;
	while(head){
		head = head->next;
		counter++;
	}
	return counter;
}
void insert_at_head(node* &head,int data){
	if(!head)
		return;
	node* temp = new node(data);
	temp->next = head;
	head = temp;
	return;
}
void insert_at_tail(node* &head,int data){
	if(!head)
		return;
	node* temp = new node(data);
	node* tail = head;
	while(tail->next){
		tail = tail->next;
	}
	tail->next = temp;
	return;
}
void insert_at_kth(node* &head,int data,int k){
	if(k==0){
		insert_at_head(head,data);
		return;
	}
	if(k>=length_of_list(head)){
		insert_at_tail(head,data);
		return;
	}
	node* tail = head;
	while(--k){
		tail = tail->next;
	}
	node* temp = new node(data);
	temp->next = tail->next;
	tail->next = temp;
	return;
}
void delete_at_head(node* &head){
	if(!head)
		return;
	node* temp = head;
	head = head->next;
	delete temp;
	return;
}
void delete_at_tail(node* &head){
	if(!head)
		return;
	node* prev = head;
	node* tail = head;
	while(tail->next){
		prev = tail;
		tail = tail->next;
	}
	prev->next = NULL;
	delete tail;
	return;
}
void delete_at_kth(node* &head,int k){
	if(k==0){
		delete_at_head(head);
		return;
	}
	if(k>=length_of_list(head)){
		delete_at_tail(head);
		return;
	}

	node* prev = head;
	node* tail = head;
	while(k--){
		prev = tail;
		tail = tail->next;
	}
	prev->next = tail->next;
	delete tail;
	return;
}
node* address_of_kth(node* head,int k){
	if(k==0){
		return head;
	}
	if(k>=length_of_list(head))
		return NULL;
	node* tail = head;
	while(k--){
		tail = tail->next;
	}
	return tail;
}
node* midpoint(node* head){//runner technique.
	if(head->next == NULL || head->next->next == NULL){
		return head;
	}
	node* fast = head;
	node* slow = head;
	while(fast->next && fast->next->next){
		fast = fast->next->next;
		slow = slow->next;
	} 
	return slow;
}
bool find_element(node* head,int data){
	if(!head)
		return false;
	if(head->data == data)
		return true;
	return find_element(head->next,data);
}
void swap(node* &head,int i,int j){
	//case 1. i=0 & j=1
	if(i==0 && j==1){
		node* temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		return;
	}
	//case 2. i=0
	if(i==0){
		node *bprev = address_of_kth(head,j-1);
		node *b = bprev->next;
		node *n = b->next;

		b->next = head->next;
		bprev->next = head;
		head->next = n;
		head = b;
		return;
	}
	//case 3. j-i = 1
	if(j-i==1){
		node* aprev = address_of_kth(head,i-1);
		node* a = aprev->next;
		node* b = a->next;
		node* n = b->next;

		aprev->next = b;
		b->next = a;
		a->next = n;
		return;
	}

	node* aprev = address_of_kth(head,i-1);
	node* bprev = address_of_kth(head,j-1);
	node* a = aprev->next;
	node* b = bprev->next;
	node* n = b->next;

	b->next = a->next;
	aprev->next = b;
	bprev->next = a;
	a->next = n;
	return;
}
node* kth_node_from_last(node* head,int k){
	if(!head)
		return head;
	static int i = k;
	node* it = kth_node_from_last(head->next,i);
	i--;
	if(i==0){
		return head;
	}
	return it;
}
pair<node*,node*>reverse(node* head){
	if(!(head->next)){
		pair<node*,node*>p;
		p.first = head;
		p.second = head;
		return p;
	}

	pair<node*,node*>p = reverse(head->next);
	p.second->next = head;
	p.second = head;
	(p.second)->next = NULL;
	return p;
}
pair<node*,node*> k_reverse(node* head,int k){
	if(!head){
		pair<node*,node*>p(NULL,NULL);
		return p;
	}
	node* tail = head;
	while(--k){
		if(!(tail->next))
			break;
		tail = tail->next;
	}
	node* newhead = tail->next;
	tail->next = NULL;
	pair<node*,node*>p = reverse(head);
	pair<node*,node*>currp = k_reverse(newhead,k);
	p.second->next = currp.first;
	p.second = currp.second;
	return  p;

}
node* merge_sorted_list(node* head1,node* head2){
	if(!head1)
		return head2;
	if(!head2)
		return head1;
	node* head = NULL;
	if(head1->data > head2->data){
		head = head2;
		head2 = head2->next;
	}else{
		head = head1;
		head1 = head1->next;
	}
	node* tail = head;
	while(head1 != NULL && head2 != NULL){
		if(head1->data > head2->data){
			tail->next = head2;
			head2 = head2->next;
			tail = tail->next;
		}else{
			tail->next = head1;
			head1 = head1->next;
			tail = tail->next;
		}
	}
	if(head1){
		tail->next = head1;
	}
	if(head2){
		tail->next = head2;
	}
	return head;
}
node* merge_sort(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* mid = midpoint(head);

	node* a = head;
	node* b = mid->next;
	mid->next = NULL;

	a = merge_sort(a);
	b = merge_sort(b);

	node* c = merge_sorted_list(a,b);


	return c;
}
void printlist(node* head){
	if(!head){
		return;
	}
	while(head){
		cout<<head->data<<"->";
		head = head->next;
	}
	return;
}

int main(){
	node* head = NULL;
	createlist(head);
	printlist(head);
	//cout<<endl<<length_of_list(head)<<endl;

	//insert_at_head(head,25);
	//insert_at_tail(head,69);
	// insert_at_kth(head,123,3);
	// printlist(head);
	// cout<<endl;
	// delete_at_head(head);
	// delete_at_tail(head);
	// delete_at_kth(head,3);
	// printlist(head);
	//cout<<address_of_kth(head,3)->data;
	//cout<<endl<<midpoint(head);
	// cout<<find_element(head,5)<<endl<<find_element(head,3000)<<endl;
	// swap(head,2,5);
	// swap(head,0,1);
	// swap(head,7,8);
	// node* head1 = NULL;
	// createlist(head1);
	// cout<<endl;
	// printlist(head1);
	cout<<endl;

	printlist(merge_sort(head));
	return 0;
}