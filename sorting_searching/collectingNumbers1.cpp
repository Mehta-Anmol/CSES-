#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    long long count = 1;
    unordered_map<long long, long long> mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]] = i+1;
    }
    for(int i=1;i<n;i++){
        if(mpp[i] > mpp[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}