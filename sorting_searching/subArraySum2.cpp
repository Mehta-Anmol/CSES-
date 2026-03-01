#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& nums, int n, int k){
    map<long long,long long> mpp;
    mpp[0] = 1;
    long long count = 0;
    long long sum = 0;

    for(int i=0;i<n;i++){
        sum+= nums[i];
        long long back = sum-k;
        count+= mpp[back];
        mpp[sum]++;
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
    cout<<solve(nums, n, k)<<endl;
    return 0;
}