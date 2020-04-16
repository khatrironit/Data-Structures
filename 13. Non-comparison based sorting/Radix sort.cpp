#include<bits/stdc++.h>
using namespace std;

void radix_helper(vector<int> &arr,int placeholder){
	int n = arr.size();

	vector<int>count_sort(10,0);

	vector<int>result(n);

	//count the number of times a particular digit occurs at the given placeholder.

	for(int i=0;i<n;i++){
		count_sort[(arr[i]/placeholder)%10]++;   //arr[i]/placeholder % 10 gives the digit at place placeholder.
	}
	//find cumulative count_sort  that will give us the index+1 till which arr needs to be filled with that particular element.
	for(int i=1;i<10;i++)
		count_sort[i] = count_sort[i] + count_sort[i-1]; 

	for(int i=n-1;i>=0;i--){
		result[count_sort[(arr[i]/placeholder)%10]-1] = arr[i];
		count_sort[(arr[i]/placeholder)%10]--;
	}

	for(int i = 0;i<n;i++)
		arr[i] = result[i];
	return;


}

void radix_sort(vector<int> &arr){
	//find the number of digits in the largest element.
	int n = arr.size();

	int max_e = arr[0];
	for(int i=1;i<n;i++)
		max_e = max(max_e,arr[i]);

	int count = 0;
	for(int i=max_e;i>0; i = i/10){
		count++;
	}


	int placeholder = 1;//ones.
	for(int i=1;i<=count;i++){
		radix_helper(arr,placeholder);
		placeholder *= 10;
	}
}

int main(){
	vector<int> arr(5);
	arr[0] =  23;
	arr[1] = 14;
	arr[2] = 454;
	arr[3] = 12354;
	arr[4] = 12;
	radix_sort(arr);
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	return 0;
}