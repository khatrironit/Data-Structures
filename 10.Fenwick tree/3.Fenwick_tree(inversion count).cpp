//inversion count = all pairs in a array such that i<j but arr[i] > arr[j]

#include<bits/stdc++.h>
using namespace std;


void update(int *BIT,int n,int index,int incr){
	while(index <=n){
		BIT[index] += incr;
		index = index + (index & (-index));
	}
	return;
}
int query(int *BIT,int index){
	int ans = 0;
	while(index > 0){
		ans += BIT[index];
		index = index - (index &(-index));
	}
	return ans;
}
int main(){
	int n;
	cin>>n;
	int arr[n+1];
	int BIT[10000] = {0};//will store the cumulative frequencies of occurences of arr[i].
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	int ans = 0;
	for(int i=n;i>=1;i--){
		ans += query(BIT,arr[i]-1);
		update(BIT,10000,arr[i],1);
	}
	cout<<endl<<ans;
	return 0;
}