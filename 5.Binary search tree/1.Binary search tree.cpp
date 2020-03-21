#include<iostream>
using namespace std;

struct node{
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~node(){
		if(left){
			delete left;
		}
		if(right){
			delete right;
		}
	}
};
void insert_in_BST(node* &root,int data){
	node* temp = new node(data);
	if(!root){
		root = new node(data);
		return;
	}
	node* it = root;
	while(it){
		if(temp->data > it->data){
			if(it->right == NULL){
				it->right = temp;
				return;
			}
			it = it->right;
		}else{
			if(it->left == NULL){
				it->left = temp;
				return;
			}
			it = it->left;
		}
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
void inorder_print(node* root){
	if(!root)
		return;
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
	return;
}
bool search(node* root,int key){
	if(!root)
		return false;
	if(root->data == key)
		return true;
	if(root->data > key)
		return search(root->left);
	else
		return search(root->right);
}
void print_in_range(node* root,int k1,int k2){
	if(!root)
		return ;
	if(root->data >= k1 && root->data <= k2){
		print_in_range(root->leftt);
		cout<<root->data<<" ";
		print_in_range(root->right);
		return;
	}
	if(root->data > k2){
		print_in_range(root->left);
		return;
	}
	if(root->data < k1){
		print_in_range(root->right);
		return;
	}
}
int main(){
	node* root = NULL;
	int arr[10] = {5,3,7,6,2,9,10,1,4,8};
	for(int i=0;i<10;i++){
		insert_in_BST(root,arr[i]);
	}
	inorder_print(root);
	return 0;
}