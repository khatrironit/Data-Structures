#include<iostream>
#include<queue>
#include<stack>
using namespace std;


struct node{
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

void create_tree(node* &root){
	int data;
	cout<<"enter data or -1 to exit ";
	cin>>data;
	if(data!=-1){
		root = new node(data);
	}else{
		return;
	}
	queue<node*>q;
	q.push(root);


	while(!q.empty()){
		node* top = q.front();
		cout<<"enter the left child of "<<top->data<<"  ";
		cin>>data;
		if(data!=-1){
			node* temp = new node(data);
			top->left = temp;
			q.push(temp);
		}
		cout<<"enter data for right child of "<<top->data<<"  ";
		cin>>data;
		if(data!=-1){
			node* temp = new node(data);
			top->right = temp;
			q.push(temp);
		}
		q.pop();
	}
	return;
}
void iterative_preorder(node* root){
	stack<node*>s;
	s.push(root);
	while(!s.empty()){
		node* top = s.top();
		cout<<top->data<<" ";
		s.pop();
		if(top->right)
			s.push(top->right);
		if(top->left)
			s.push(top->left);		
	}
	return;
}
void preorder_print_tree(node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	preorder_print_tree(root->left);
	preorder_print_tree(root->right);
	return;
}
void inorder_print_tree(node* root){
	if(!root)
		return;
	
	preorder_print_tree(root->left);
	cout<<root->data<<" ";
	preorder_print_tree(root->right);
	return;
}
void iterative_postorder(node* root){
	stack<node*>s;
	vector<int>v;
	s.push(root);
	while(!s.empty()){
		node* top = s.top();
		s.pop();
		v.insert(v.begin(),top->data);
		if(top->left)
			s.push(top->left);
		if(top->right)
			s.push(top->right);
	}
	vector<int>::iterator it;
	for(it = v.begin();it!=v.end();it++){
		cout<<(*it)<<" ";
	}
	return;
}
void postorder_print_tree(node* root){
	if(!root)
		return;
	
	preorder_print_tree(root->left);
	preorder_print_tree(root->right);
	cout<<root->data<<" ";

	return;
}
void level_order_inline_print(node* root){
	if(!root)
		return;
	queue<node*>q;
	q.push(root);
	while(!q.empty()){
		node* top = q.front();
		cout<<top->data<<" ";
		
		if(top->left){
			q.push(top->left);
		}
		if(top->right){
			q.push(top->right);
		}

		q.pop();
	}
	return;
}
void reverse_level_order_inline_print(node* root){
	if(!root)
		return;
	stack<node*>s;
	queue<node*>q;
	q.push(root);
	while(q.empty()==false){
		node* top = q.front();
		if(top->left)
			q.push(top->left);
		if(top->right)
			q.push(top->right);
		s.push(top);
		q.pop();
	}
	while(s.empty() == false){
		node* top = s.top();
		cout<<top->data<<" ";
		s.pop();
	}
	return;
}
void level_order_block_print(node* root){
	if(!root)
		return;
	queue<node*>q1,q2;
	q1.push(root);

	while(q1.empty() == false || q2.empty() == false){
		if(q2.empty()){
			//worl for q1.
			while(q1.empty()==false){
				node* top = q1.front();
				cout<<top->data<<" ";
				if(top->left)
					q2.push(top->left);
				if(top->right)
					q2.push(top->right);

				q1.pop();
			}
			cout<<endl;
		}else{
			//work for q2.
			while(q2.empty()==false){
				node* top = q2.front();
				cout<<top->data<<" ";
				if(top->left)
					q1.push(top->left);
				if(top->right)
					q1.push(top->right);
				q2.pop();
			}
			cout<<endl;
		}
	}
	return;
}
void spiral_order_print(node* root){
	if(!root)
		return;
	stack<node*>s1,s2;
	s1.push(root);
	while(s1.empty() == false || s2.empty() == false ){
		if(s2.empty()){
			//work for s1.
			while(s1.empty() == false){
				node* top = s1.top();
				cout<<top->data<<" ";
				if(top->left)
					s2.push(top->left);
				if(top->right)
					s2.push(top->right);
				s1.pop();
			}
			cout<<endl;
		}else{
			//work for s2.
			while(s2.empty() == false){
				node* top = s2.top();
				cout<<top->data<<" ";
				if(top->right)
					s1.push(top->right);
				if(top->left)
					s1.push(top->left);
				s2.pop();
			}
			cout<<endl;
		}
	}
	return;
}
void right_view(node* root){
	if(!root)
		return;
	queue<node*>q1,q2;
	q1.push(root);
	while(q1.empty() == false || q2.empty() == false){
		if(q2.empty()){
			//work for q1.
			while(q1.empty() == false){
				node* top = q1.front();
				if(q1.size() == 1)
					cout<<top->data;
				if(top->right)
					q2.push(top->right);
				if(top->left)
					q2.push(top->left);
				
				q1.pop();
			}
			cout<<endl;
		}else{
			//work for q2.
			while(q2.empty() == false){
				node* top = q2.front();
				if(q2.size() == 1)
					cout<<top->data;
				if(top->right)
					q1.push(top->right);
				if(top->left)
					q1.push(top->left);
				
				q2.pop();
			}
			cout<<endl;
		}
	}
	return;
}
void left_view(node* root){
	if(!root)
		return;
	queue<node*>q1,q2;
	q1.push(root);
	while(q1.empty() == false || q2.empty() == false){
		if(q2.empty()){
			//work for q1.
			while(q1.empty() == false){
				node* top = q1.front();
				if(q1.size() == 1)
					cout<<top->data;
				if(top->left)
					q2.push(top->left);
				if(top->right)
					q2.push(top->right);
				q1.pop();
			}
			cout<<endl;
		}else{
			//work for q2.
			while(q2.empty() == false){
				node* top = q2.front();
				if(q2.size() == 1)
					cout<<top->data;
				if(top->left)
					q1.push(top->left);
				if(top->right)
					q1.push(top->right);
				q2.pop();
			}
			cout<<endl;
		}
	}
	return;
}

int main(){
	node* root = NULL;
	create_tree(root);
	cout<<endl;
	preorder_print_tree(root);
	cout<<endl<<endl;
	iterative_preorder(root);
	cout<<endl<<endl;
	inorder_print_tree(root);
	cout<<endl<<endl;
	postorder_print_tree(root);
	cout<<endl<<endl;
	iterative_postorder(root);
	cout<<endl<<endl;
	level_order_inline_print(root);
	cout<<endl<<endl;
	reverse_level_order_inline_print(root);
	cout<<endl<<endl;
	level_order_block_print(root);
	cout<<endl<<endl;
	spiral_order_print(root);
	cout<<endl<<endl;
	right_view(root);
	cout<<endl<<endl;
	left_view(root);
	return 0;
}