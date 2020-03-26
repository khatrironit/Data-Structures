#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    map<int ,int>m;
    for(int i=0;i<n;i++){
        int l1 = 0;
        int l2 = 0;
        if(m.find(arr[i])==m.end()){
            if(m.find( arr[i]-1 ) != m.end() ){//right boundary of the streak
                l1 = m[ arr[i]-1 ];
            }
            if(m.find( arr[i]+1 ) != m.end() ){//left boundary of the streak
                l2 = m[ arr[i]+1 ];
            }
            m[arr[i]] = 1+l1+l2;
            if(l1 == 0 && l2 != 0){
                m[ arr[i]+l2 ]++;
            }
            if(l1 != 0 && l2 == 0){
                m[ arr[i]-l1 ]++;
            }
            if(l1 != 0 && l2 != 0){
                m[ arr[i]+l2 ] = 1+l1+l2;
                m[ arr[i]-l1 ] = 1+l1+l2;
            }
        }  
    }
     int max_ = 0;
     for(auto it:m){
        if((it.second) > max_)
            max_ = (it.second);
     }
     cout<<max_;
    delete [] arr;
	return 0;
}