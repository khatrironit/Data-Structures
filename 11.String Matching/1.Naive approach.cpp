//print the indices of string where pattern is found.

#include<iostream>
using namespace std;

void naiveMatching(string s,string p);

int main(){
	string s,p;
	cin>>s>>p;
	naiveMatching(s,p);
	return 0;
}















void naiveMatching(string s,string p){
	for(int i=0;i<=s.size()-p.size();i++){
		int j;
		for(j=0;j<p.size();j++){
			if(s[i+j] != p[j]){
				break;
			}
		}
		if(j==p.size()){
			cout<<"pattern found at "<<i<<"."<<endl;
		}
	}
	return;
}