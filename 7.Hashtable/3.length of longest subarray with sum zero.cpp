#include<iostream>
#include<map>
using namespace std;

int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}

	map<int,int> m;
	int prefix = 0;
	int len = 0;
	int ans = 0;
	for(int i=0;i<n;i++){
		prefix += arr[i];
		if(prefix == 0){
			len = i;
		}else if(m.find(prefix) != m.end()){
			len = i - m[prefix];
		}else{
			m[prefix] = i;
		}
		
		
		ans = max(ans,len+1);
	}
	cout<<ans;
	return 0;
}