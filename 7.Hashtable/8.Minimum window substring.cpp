 //find the length of the minimum window that contains all the characters of a given pattern.
//str = adocecodebanc
//pat = abc
//output = 4 i.e. "banc"


#include<bits/stdc++.h>
using namespace std;

string  min_window_substring(string s,string pat);

int main(){
	string s,pat;
	cin>>s>>pat;

	string len = min_window_substring(s,pat);

	cout<<len;
	return 0;

}









string  min_window_substring(string s,string pat){
	int n = s.size();
	int m = pat.size();

	if(m>n){
		return "";
	}

	int hash_str[256] = {0};
	int hash_pat[256] = {0};

	for(int i=0;i<m;i++){
		hash_pat[pat[i]]++;
	}

	int start = 0,start_index = -1,min_len = 999999;
	int count = 0;
	for(int i=0;i<n;i++){
		//grow window
		hash_str[s[i]]++;

		if(hash_str[s[i]]<=hash_pat[s[i]])
			count++;
		if(count == m){
			//shrink window.
			int len = i+1;
			while(hash_str[s[start]]>hash_pat[s[start]]){
				hash_str[s[start]]--;
				start++;
			}
			len = i-start+1;
			min_len = min(min_len,len);
			start_index = start;
		}

	}
	if(start_index == -1)
		return "";
	return s.substr(start_index,min_len);
}