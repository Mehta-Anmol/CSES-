#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<vector<long long>> ans(n,vector<long long>(2));
    for(long long i=0;i<n;i++){
        cin>>ans[i][0]>>ans[i][1];
    }

    long long count = 0;
    sort(ans.begin(),ans.end(),[](auto &a, auto &b){
        return a[1] < b[1];
    });
    long long prevmax = ans[0][1];
    for(long long i=1;i<n;i++){
        long long start = ans[i][0];
        long long end = ans[i][1];
        if(start >= prevmax){
            count++;
            prevmax = end;
        }
    }
    cout<<count+1<<endl;
    return 0;
}
