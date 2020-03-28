//if (A.B)%m = 1 then B is the multiplicative modulo inverse of A. A and m must be co-prime.


#include<bits/stdc++.h>
using namespace std;

pair<int,int>modulo_inverse(int A,int m){
	if(m==0){
		pair<int,int> p(1,0);
		return p;
	}
	pair<int,int> small_ans = modulo_inverse(m,A%m);
	pair<int,int> ans;
	ans.first = small_ans.second;
	ans.second = small_ans.first - (A/m)*small_ans.second;
	return ans;
}
int main(){
	int A = 5;
	int m = 17;
	pair<int,int>ans = modulo_inverse(A,m);
	cout<<ans.first;
	return 0;
}