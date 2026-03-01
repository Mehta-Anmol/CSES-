#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& nums, int n, int k){
    unordered_map<long long,long long> mpp;
    long long count = 0;
    long long presum = 0;
    mpp[0] = 1;
    for(int i=0;i<n;i++){
        presum+= nums[i];

        long long back = presum-k;
        count+= mpp[back];
        mpp[presum]++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<solve(nums,n,k)<<endl;
    return 0;
}