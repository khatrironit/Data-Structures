#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}

	int max_ = *max_element(v.begin(),v.end());
	int min_ = *min_element(v.begin(),v.end());
	map<int,int>m;
	for(int i=0;i<n;i++){
		m[v[i]]++;
	}
	int count = 0;
	int ans = 0;
	for(int i=min_;i<=max_;i++){
		if(m.find(i+1)!=m.end()){
			count++;
		}else{
			ans = max(ans,count+1);
			count = 0;
		}
	}
	cout<<ans;
	return 0;
}