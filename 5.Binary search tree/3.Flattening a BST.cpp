#include<iostream>
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
node* BST_from_array(int* arr,int s,int e){
	if(s>e)
		return NULL;
	int mid = (s+e)/2;
	node* root = new node(arr[mid]);
	root->left = BST_from_array(arr,s,mid-1);
	root->right = BST_from_array(arr,mid+1,e);
	return root;
}
pair<node*,node*> flatten(node* root){
	if(!root){
		pair<node*,node*> p(NULL,NULL);
		return p;
	}
	//case 1. leaf node.
	if(root->left == NULL && root->right == NULL){
		pair<node*,node*> p(root,root);
		return p;
	}
	//case 2. one child.
	if(root->left!=NULL && root->right==NULL){
		pair<node*,node*> left = flatten(root->left);
		pair<node*,node*> p;
		(left.second)->right = root;
		p.first = left.first;
		p.second = root;
		return p;
	}
	if(root->left == NULL && root->right!=NULL){
		pair<node*,node*> right = flatten(root->right);
		pair<node*,node*> p;
		root->right = right.first;
		p.first = root;
		p.second = right.second;
		return p;
	}
	//two child.
	pair<node*,node*> left = flatten(root->left);
	pair<node*,node*> right = flatten(root->right);

	pair<node*,node*> p;
	left.second->right = root;
	root->right = right.first;
	p.first = left.first;
	p.second = right.second;
	return p;
}
void print_flattened_list(node* root){
	if(!root)
		return;
	while(root){
		cout<<root->data<<" ";
		root = root->right;
	}
	return;
}
int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	node* root = BST_from_array(arr,0,9);


	pair<node*,node*> p = flatten(root);
	print_flattened_list(p.first);
	return 0;
}