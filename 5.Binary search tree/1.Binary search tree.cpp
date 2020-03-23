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
		return search(root->left,key);
	else
		return search(root->right,key);
}
void print_in_range(node* root,int k1,int k2){
	if(!root)
		return ;
	if(root->data >= k1 && root->data <= k2){
		print_in_range(root->left,k1,k2);
		cout<<root->data<<" ";
		print_in_range(root->right,k1,k2);
		return;
	}
	if(root->data > k2){
		print_in_range(root->left,k1,k2);
		return;
	}
	if(root->data < k1){
		print_in_range(root->right,k1,k2);
		return;
	}
}
node* delete_node(node* root,int key){
	if(!root)
		return NULL;
	if(root->data == key){
		//case 1. leaf node.
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}
		//case 2. one child.
		if(root->left == NULL && root->right != NULL){
			node* temp = root->right;
			delete root;
			return temp;
		}
		if(root->left != NULL && root->right == NULL){
			node* temp = root->left;
			delete root;
			return temp;
		}
		//case 3. two child.
		node* parent = root->right;
		node* it = root->right;
		root->right = NULL;
		while(it->left){
			it = it->left;
		}
		it->left = root->left;
		root->left = NULL;
		delete root;
		return parent;
	}
	if(root->data > key)
		root->left = delete_node(root->left,key);
	else
		root->right = delete_node(root->right,key);
	return root;
}
bool isBST(node* root,int minv = INT_MIN,int maxv = INT_MAX){
	if(!root)
		return true;
	if((root->data >= minv && root->data <=maxv) && isBST(root->left,minv,root->data) && isBST(root->right),root->data,maxv)
		return true;
	else 
		return false;
}
node* BST_from_sorted_array(int *arr,int s,int e){
	if(s>e)
		return NULL;
	int mid = (s+e)/2;
	node* root = new node(arr[mid]);
	root->left = BST_from_sorted_array(arr,s,mid-1);
	root->right = BST_from_sorted_array(arr,mid+1,e);
	return root;
}
int main(){
	//node* root = NULL;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	// for(int i=0;i<10;i++){
	// 	insert_in_BST(root,arr[i]);
	// }
	// inorder_print(root);

	// cout<<endl<<search(root,9)<<endl;
	// print_in_range(root,3,9);
	// node* root1 = delete_node(root,5);
	// //root = delete_node(root,2);
	// cout<<endl;
	// inorder_print(root1);
	node* root = BST_from_sorted_array(arr,0,9);
	//cout<<endl<<isBST(root);
	inorder_print(root);

	return 0;
}