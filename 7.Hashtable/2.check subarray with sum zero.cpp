#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool present = false;
	set<int>s;
	int prefix = 0;
	for(int i=0;i<n;i++){
		prefix += arr[i];

		if(prefix == 0 || s.find(prefix) != s.end()){
			present = true;
			break;
		}
		s.insert(prefix);
	}
	if(present)
		cout<<"zero sum subarray is present";
	else
		cout<<"zero sum subarray is not present";
	delete [] arr;
	return 0;
}