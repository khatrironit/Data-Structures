//fenwick tree can only be used to find max till an index i.e. in range(1,index) as it can only be used in prefix type problems
//to find max in a given range use segment tree.
#include<bits/stdc++.h>
using namespace std;

void update(int *BIT,int n,int index,int value){
	while(index <= n){
		BIT[index] = max(BIT[index],value);
		index = index + (index & (-index));
	}
	return;
}
//returns max value in range(1,index)
int query(int *BIT,int index){
	int ans = BIT[index];
	while(index > 0){
		ans = max(ans,BIT[index]);
		index = index - (index & (-index));
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n+1];
	int BIT[n+1] = {0};
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		update(BIT,n,i,arr[i]);
	}
	for(int i=1;i<=n;i++){
		cout<<BIT[i]<<" ";
	}
	
	return 0;
}