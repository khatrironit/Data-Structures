#include<iostream>
#include<climits>
using namespace std;


int lazy[10000] = {0};

void buid_segment_tree(int *a,int s,int e,int * tree,int index){
	//leaf node
	if(s==e){
		tree[index] = a[s];
		return;
	}

	//call on both sides.
	int mid = (s+e)/2;
	buid_segment_tree(a,s,mid,tree,2*index);
	buid_segment_tree(a,mid+1,e,tree,2*index + 1);

	tree[index] = min(tree[2*index],tree[2*index + 1]);
	return;
}
int query_lazy(int* tree,int s,int e,int qs,int qe,index){
	//first step - if lazy value is non zero never go down first resolve the node value then proceed.
	if(lazy[index] != 0){
		tree[index] = tree[index]+lazy[index];

		if(s!=e){//if not a leaf node pass the lazy values to the children of the node.
			lazy[2*index] = lazy[2*index] + lazy[index];
			lazy[2*index + 1] = lazy[2*index + 1] + lazy[index];
		}
		//update lazy value of node.
		lazy[index] = 0;
	}
	//no overlap
	if(qs > e || qe < s){
		return;
	}
	//complete overlap.
	if(qs <= s && qe >= e){//no need to resolve lazy value as it has already been resolved.
		return tree[index];
	}

	//partial overlap.
	int mid = (s+e)/2;
	int left = query_lazy(tree,s,mid,qs,qe,2*index);
	int right = query_lazy(tree,mid+1,e,qs,qe,2*index + 1);
	int ans = min(tree[2*index],tree[2*index + 1]);
	return ans;
}

void update_range_lazy(int* tree ,int s,int e,int i,int j,int incr,int index){
	//if lazy value of the node is non zero then first resolve it then proceed.
	if(lazy[index] != 0){
		tree[index] = tree[index]+lazy[index];

		//pass lazy value to child subtrees if not a leaf node.
		if(s!=e){
			lazy[2*index]+=lazy[index];
			lazy[2*index + 1]+=lazy[index];
		}
		lazy[index] = 0;
	}

	//no overlap.
	if(i>e || j<s){
		return;
	}
	//complete overlap
	if(i=s && j=e){
		//the lazy value has already been resolved.update the value of the node and pass the incr value as lazy value to child subtrees.
		tree[index] = tree[index]+incr;

		if(s!=e){
			lazy[2*index] = lazy[2*index] + incr;
			lazy[2*index + 1] = lazy[2*index + 1] + incr;
		}
		return;
	}
	//partial overlap.
	int mid = (s+e)/2;
	update_range_lazy(tree,s,mid,i,j,incr,2*index);
	update_range_lazy(tree,mid+1,e,i,j,incr,2*index + 1);
	tree[index] = min(tree[2*index],tree[2*index + 1]);
	return;
}
int main(){
	int arr[] = {1,3,2,-5,6,4};
	int n = sizeof(arr)/sizeof(int);

	int * tree = new int[4*n + 1];
	buid_segment_tree(arr,0,n-1,tree,index);



	return 0;
}