#include<bits/stdc++.h>
using namespace std;

long long func(int i,long long curr,long long total, vector<int>& nums, int n){
    if(i == n){
        long long other = total-curr;
        return abs(other-curr);
    }

    return min(func(i+1,curr+nums[i],total,nums,n),func(i+1,curr,total,nums,n));
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    long long total = 0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        total+= nums[i];
    }
    cout<<func(0,0,total,nums,n)<<endl;
    
    return 0;
}