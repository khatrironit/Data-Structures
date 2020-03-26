#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int * arr = new int[n];
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        int count = 0;
        int lb = arr[i];
        if(s.find(lb-1) != s.end()){
            continue;
        }else{
            while(s.find(lb) != s.end()){
                count++;
                lb++;
            }
        }
        ans = max(ans,count);
    }
    cout<<ans;
    delete [] arr;
    return 0;
}
