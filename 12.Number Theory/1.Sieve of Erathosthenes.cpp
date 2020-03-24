//given a number n find the number of prime numbers less than equal to n.

#include<iostream>
using namespace std;

int sieve(int n){
	bool arr[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = true;
	}
	arr[0] = arr[1] = false;
	for(int i=2;i*i<=n;i++){
		if(arr[i]){
			for(int j = i*i;j<=n;j+=i){
				arr[j] = false;
			}
		}
	}
	int count = 0;
	for(int i=0;i<=n;i++){
		if(arr[i])
			count++;
	}
	return count;
}
int main(){
	int n = 100;
	cout<<sieve(n);
	return 0;
}