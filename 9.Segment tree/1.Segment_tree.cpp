#include<iostream>
#include<climits>
using namespace std;

void build_Segment_Tree(int *a,int s,int e,int *tree,int index){
	if(s==e){
		tree[index] = a[s];
		return;
	}

	int mid = (s+e)/2;
	build_Segment_Tree(a,s,mid,tree,2*index);
	build_Segment_Tree(a,mid+1,e,tree,(2*index +1));

	tree[index] = min(tree[2*index],tree[2*index + 1]);

	return;
}
int query_Segment_Tree(int * tree,int s,int e,int qs,int qe,int index){// s & e are starting and ending index of input array not tree.
	// Case 1: complete overlap.
	if(qs<=s && qe>=e){
		return tree[index];
	}
	//Case 2: no overlap.
	if(qs>=e || qe <= s){
		return INT_MAX;
	}
	// Case 3: Partial overlap.
	int mid = (s + e)/2;
	int left = query_Segment_Tree(tree,s,mid,qs,qe,2*index);
	int right = query_Segment_Tree(tree,mid+1,e,qs,qe,2*index +1);
	return min(left,right);
}
void update_node_Segment_Tree(int * tree,int s,int e,int i,int incr,int index){
	// return if update_index doesn't lie in range.
	if(i<s || i>e){
		return;
	}
	// update value on reaching the leaf node i.e. required index
	if(s==e){
		tree[index] = tree[index]+incr;
	}
	// call on both sides if update index lies in range.
	int mid = (s+e)/2;
	update_node_Segment_Tree(tree,s,mid,i,incr,2*index);
	update_node_Segment_Tree(tree,mid+1,e,i,incr,index);
	tree[index] = min(tree[2*index],tree[2*index + 1]);
	return;
}
void update_range_Segment_Tree(int * tree,int s,int e,int i,int j,int incr,int index){
	//out of bounds - no overlap
	if(j < s || i > e){
		return;
	}
	//update if leaf node.
	if(s==e){
		tree[index]+=incr;
		return;
	}
	//partial and complete overlap
	int mid = (s+e)/2;
	update_range_Segment_Tree(tree,s,mid,i,j,incr,2*index);
	update_range_Segment_Tree(tree,mid+1,e,i,j,incr,2*index + 1);
	tree[index] = min(tree[2*index],tree[2*index + 1]);
	return;
}
int main(){
	int arr[] = {1,3,2,-5,6,4};
	int n = sizeof(arr)/sizeof(int);

	int tree[4*n + 1] = {0};
	build_Segment_Tree(arr,0,n-1,tree,1);

	for(int i = 0 ; i <= 4*n ; i++){
		cout<<tree[i]<<" ";
	}
	return 0;
}