//factorial of 100 has 158 digits , even long long can save a number of only upto 18 digits.
//so we will use an array to store our result in reverse order.

#include<iostream>
using namespace std;
void multiply(int * arr,int &n,int multiplier){//pass n by reference.
	int carry = 0;

	for(int i=0;i<n;i++){
		int product = arr[i]*multiplier + carry;
		arr[i] = product % 10;
		carry = product/10;
	}
	while(carry){
		arr[n] = carry % 10;
		carry = carry/10;
		n++;       //&n
	}
}
void factorial_big_int(int number){
	int arr[1000] = {1}; //factorial of 1;
	int n = 1; //denotes the index till where array is filled.

	for(int i=2;i<=number;i++){
		multiply(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		cout<<arr[i];
	}
	return;
}
int main(){
	int number;
	cin>>number;
	factorial_big_int(number);
	return 0;
}