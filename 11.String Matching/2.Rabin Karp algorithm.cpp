//uses a rolling hash function to generate a unique hash for pattern and substrings.
//if matched then double check for that particular substring.


#include<bits/stdc++.h>
#define ll long long
#define prime 119
using namespace std;

ll hash(string s);
void Rabin_karp(string s,string p);


int main(){
	string s,p;
	cin>>s>>p;
	Rabin_karp(s,p);
	return 0;
}









ll hash(string s){
	int n = s.size();
	ll result = 0;
	for(int i=0;i<n;i++){
		result += s[i]*pow(prime,i);
	}
	return result;
}

void Rabin_karp(string s,string p){
	ll p_hash = hash(p);
	int n = s.size();
	int m = p.size();

	ll temp_hash = hash(s.substr(0,m));

	for(int i=0;i<n;i++){
		if(temp_hash == p_hash){
			int j;
			for(j=0;j<m;j++){
				if(s[i+j] != p[j])
					break;
			}
			if(j==m)
				cout<<"pattern found at "<<i<<"."<<endl;
		}
		//update hash in O(1) complexity.
		temp_hash = (temp_hash - s[i])/prime + (ll)s[i+m]*(ll)pow(prime,m-1);
	}

	return;
}