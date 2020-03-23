///Merge two Bsts in O(m+n) time complexity.

// Step 1. store inorder transversals of the BSTs in arrays, these arrays will be sorted.
// step 2. merge the sorted arrays in O(m+n) time complexity.
// step 3. make BST from sorted array.

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
};
void  inorder_array(node* root,int *arr,int *index){
	if(!root)
		return;
	inorder_array(root->left,arr,index);
	arr[*index] = root->data;
	(*index)++;
	inorder_array(root->right,arr,index);
	return;
}
int* merge_sorted_arrays(int *arr1,int n,int *arr2,int m){
	if(n==0 || m==0)
		return NULL;
	int i = 0;
	int j = 0;
	int k = 0;
	int* arr3 = new int[m+n];
	while(i<n && j<m){
		if(arr1[i] > arr2[j]){
			arr3[k] = arr2[j];
			j++;
		}else{
			arr3[k] = arr1[i];
			i++;
		}
		k++;
	}
	if(i!=n){
		while(i<n){
			arr3[k] = arr1[i];
			i++;
			k++;
		}
	}
	if(j!=m){
		arr3[k] = arr2[j];
		k++;
		j++;
	}
	return arr3;
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
void inorder_print(node* root){
	if(!root)
		return;
	inorder_print(root->left);
	cout<<root->data<<" ";
	inorder_print(root->right);
	return;
}
// node* mergeBST(node* root1,int n,node* root2,int m){
// 	int arr1[n];
// 	inorder_array(root1,arr1);

// 	int arr2[m];
// 	inorder_array(root2,arr2);

// 	int *arr3 = merge_sorted_arrays(arr1,n,arr2,m);

// 	node* root = BST_from_sorted_array(arr3,0,m+n-1);
// 	return root;
// }
int main(){
	int n = 10;
	int arr1[n] = {1,3,5,7,9,11,13,15,17,19};
	int m = 10;
	int arr2[m] = {2,4,6,8,10,12,14,16,18,20};

	node* root1 = BST_from_sorted_array(arr1,0,n-1);
	node* root2 = BST_from_sorted_array(arr2,0,m-1);
    

    int *inarr1 = new int[n];
    int i = 0;
    inorder_array(root1,inarr1,&i);
    for(int i=0;i<n;i++)
    	cout<<inarr1[i]<< " ";
    cout<<endl<<endl;

    int *inarr2 = new int[m];
    int j = 0;
    inorder_array(root2,inarr2,&j);
    for(int i=0;i<m;i++)
    	cout<<inarr2[i]<< " ";
    cout<<endl<<endl;
	
	int* combined = merge_sorted_arrays(inarr1,n,inarr2,m);
	for(int i=0;i<m+n;i++)
    	cout<<combined[i]<< " ";
    cout<<endl<<endl;



	node* root = BST_from_sorted_array(combined,0,m+n-1);
	inorder_print(root);
	return 0;
}