#include<bits/stdc++.h>
using namespace std;

void update(int *BIT,int n,int index,int incr){
	while(index <= n){
		BIT[index] += incr;
		index = index + (index & (-index));
	}
	return;
}
// return the sum of range[1,index]
int query(int *BIT,int index){
	int sum = 0;
	while(index>0){
		sum += BIT[index];
		index = index - (index & (-index));
	}
	return sum;
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
	//cout<<query(BIT,4);
	int q;
	cin>>q;
	while(q--){
		int i,j;
		cin>>i>>j;
		cout<<endl<<query(BIT,j)-query(BIT,i-1);
	}
	return 0;
}