// find gcd(a,b) where a<10^250(can't be stored in int or long long) and b<40,000


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int advanced_gcd(string a,int b){
	int prev_gcd = int(a[0]-'0')%b;
	int curr_gcd = prev_gcd;

	int i=1;
	while(a[i]!='\0'){
		curr_gcd = ((prev_gcd*10)%b + int(a[i]-'0')%b )%b;
		prev_gcd = curr_gcd;
		i++;
	}
	return __gcd(b,curr_gcd);
}
int main(){
	string a;
	cin>>a;
	int b;
	cin>>b;
	cout<<advanced_gcd(a,b);
	return 0;

}