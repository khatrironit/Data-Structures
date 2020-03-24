//given a linear diophantine eqn ax + by = gcd(a,b). find integral values of x and y.

#include<iostream>
using namespace std;

pair<int,int> Extended_euclid(int a,int b){//first = x and second = y
	if(b==0){
		pair<int,int> p(1,0);
		return p;
	}
	pair<int,int>small_ans = Extended_euclid(b,a%b);
	pair<int,int>ans;
	ans.first = small_ans.second;
	ans.second = small_ans.first - small_ans.second*(a/b);
	return ans;
}
int main(){
	int a = 16;
	int b = 10;
	pair<int,int>ans = Extended_euclid(a,b);
	cout<<ans.first<<" "<<ans.second;
	return 0;
}