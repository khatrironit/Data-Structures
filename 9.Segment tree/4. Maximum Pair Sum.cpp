//Given an array of integers and a range , return the maximum pair sum in that range.
//number of queries > 100000


//max pair sum = max_element + second_max_element
#include<iostream>
#include<climits>
using namespace std;

void build_segment_tree(int * arr,int s,int e,pair<int,int> *tree,int index){//pair => (max element,second max element)
	if(s==e){
		//leaf node.
		tree[index] = make_pair(arr[s],INT_MIN);
		return;
	}

	int mid = (s+e)/2;
	build_segment_tree(arr,s,mid,tree,2*index);
	build_segment_tree(arr,mid+1,e,tree,2*index + 1);

	//max element = max(left_max,right_max)
	tree[index].first = max(tree[2*index].first, tree[2*index + 1].first);

	//second max element = (if left_max is max element than second max can be either of left_second_max or right_max
	//							similarly if right_max is the max element then second max can be either of right_second_max or left_max)
	tree[index].second = min(max(tree[2*index].second,tree[2*index + 1].first),max(tree[2*index].first,tree[2*index+1].second));

	return;
}
void update_tree(pair<int,int> *tree,int s,int e,int i,int value,int index){
	//out of bounds.
	if(i>e || i<s){
		return;
	}
	//update the leaf node.
	if(s==e && s==i){
		tree[index].first = value;
		return;
	}
	//complete and partial overlap.
	int mid = (s+e)/2;
	update_tree(tree,s,mid,i,value,2*index);
	update_tree(tree,mid+1,e,i,value,2*index + 1);

	pair<int,int>left = tree[2*index];
	pair<int,int>right = tree[2*index + 1];

	tree[index].first = max(left.first,right.first);
	tree[index].second = min(max(left.second,right.first),max(left.first,right.second));

	return;
}
pair<int,int> query_segment_tree(pair<int,int> *tree,int s,int e,int qs,int qe,int index){
	//case 1. no overlap.
	if(qs>e || qe <s){
		pair<int,int>p(INT_MIN,INT_MIN);
		return p;
	}
	//case 2.Complete overlap.
	if(qs<=s && qe>=e){
		return tree[index];
	}
	//case 3. partial overlap.
	int mid = (s+e)/2;

	pair<int,int>left = query_segment_tree(tree,s,mid,qs,qe,2*index);
	pair<int,int>right = query_segment_tree(tree,mid+1,e,qs,qe,2*index + 1);

	pair<int,int>temp;
	temp.first = max(left.first,right.first);
	temp.second = min(max(left.second,right.first),max(right.second,left.first));

	return temp;
}
int main(){
	int arr[] = {4,1,8,3,2,9};
	int n = sizeof(arr)/sizeof(int);

	pair<int,int> tree[4*n];

	build_segment_tree(arr,0,n-1,tree,1);

	pair<int,int> maxpair = query_segment_tree(tree,0,n-1,0,3,1);
	int ans;
	if(maxpair.second != INT_MIN)
		ans = maxpair.first + maxpair.second;
	else
		ans = maxpair.first;
	cout<<ans<<endl;


	update_tree(tree,0,n-1,1,5,1);


	pair<int,int> maxpair1 = query_segment_tree(tree,0,n-1,0,3,1);
	int ans1;
	if(maxpair1.second != INT_MIN)
		ans1 = maxpair1.first + maxpair1.second;
	else
		ans1 = maxpair1.first;
	cout<<ans1;
	return 0;
}