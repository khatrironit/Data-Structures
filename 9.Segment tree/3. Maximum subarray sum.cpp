// Given an array and a range in array find the maximum subarray sum in that range using segment tree.
// (number of queries > 100000)


#include<iostream>
using namespace std;

struct sum {
	int prefix_sum;
	int suffix_sum;
	int total_sum;
	int maximum_subarray_sum;
};

void buildTree(int * arr,int s,int e,sum *tree,int index){
	if(s==e){
		//leaf node.
		tree[index].prefix_sum = arr[s];
		tree[index].suffix_sum = arr[s];
		tree[index].total_sum = arr[s];
		tree[index].maximum_subarray_sum = arr[s];
		return;
	}

	int mid = (s+e)/2;

	buildTree(arr,s,mid,tree,2*index);
	buildTree(arr,mid+1,e,tree,2*index + 1);

	//max(prefix sum of left part, totalsum of left part + prefix of right part)
	tree[index].prefix_sum = max(tree[2*index].prefix_sum,tree[2*index + 1].prefix_sum + tree[2*index].total_sum);
	//max(suffix sum of left part + total sum of right part , suffix sum of right part)
	tree[index].suffix_sum = max(tree[2*index].suffix_sum + tree[2*index + 1].total_sum, tree[2*index + 1].suffix_sum);
	//(totalsum of left part + total sum of right part)
	tree[index].total_sum = tree[2*index].total_sum + tree[2*index + 1].total_sum;
	// case 1. maximum subarray sub lies in the left part.
	// case 2. maximum subarray sum lies in the right part.
	// case 3. maximum subarray sum lies partially in right and partially in left part i.e. suffix sum of left + prefix sum of right part.
	// ans = max(case 1 ,case 2 ,case 3)
	tree[index].maximum_subarray_sum = max(tree[2*index].suffix_sum + tree[2*index + 1].prefix_sum, max(tree[2*index].maximum_subarray_sum, tree[2*index + 1].maximum_subarray_sum));

	return;
}


sum queryTree(sum *tree,int s,int e,int qs,int qe,int index){
	// case 1. no overlap-return INT_MIN.
	if(qs>e || qe<s){
			return ((sum){INT_MIN,INT_MIN,0,INT_MIN});
	}
	// case 2. complete overlap-return tree[index]
	if(qs<=s && qe>=e){
		return tree[index];
	}
	// case 3. Partial overlap - call on both sides.
	int mid = (s+e)/2;

	sum left = queryTree(tree,s,mid,qs,qe,2*index);
	sum right = queryTree(tree,mid+1,e,qs,qe,2*index + 1);

    sum temp;
    temp.prefix_sum = max(left.prefix_sum,right.prefix_sum + left.total_sum);
    temp.suffix_sum = max(right.suffix_sum,right.total_sum + left.suffix_sum);
    temp.total_sum = left.total_sum + right.total_sum;
    temp.maximum_subarray_sum = max(left.suffix_sum + right.prefix_sum , max(left.maximum_subarray_sum,right.maximum_subarray_sum));

    return temp;

}

int main(){
	int arr[] = {1,3,-4,5,-2};
	int n = sizeof(arr)/sizeof(int);

	sum tree[4*n + 1];

	buildTree(arr,0,n-1,tree,1);
	cout<<queryTree(tree,0,n-1,0,1,1).maximum_subarray_sum;
	return 0;
}