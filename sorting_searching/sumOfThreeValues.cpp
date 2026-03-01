#include<bits/stdc++.h>
using namespace std;

vector<long long> find(vector<pair<long long,long long>> nums, long long n, long long x){
    sort(nums.begin(),nums.end());
    
    for(long long i=0;i<n-2;i++){
        long long j = i+1;
        long long k = n-1;
        while(j < k){
            long long sum = nums[i].first+nums[j].first+nums[k].first;
            if(sum == x){
                return {nums[i].second,nums[j].second,nums[k].second};
            }
            else if(sum > x){
                k--;
            }
            else{
                j++;
            }
        }
    }
    return {-1};
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n,x;
    cin>>n>>x;
    vector<pair<long long,long long>> nums(n);
    for(long long i=0;i<n;i++){
        long long num;
        cin>>num;
        nums[i] = {num,i+1};
    }
    vector<long long> ans = find(nums,n,x);
    if(ans[0] == -1){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(long long i: ans){
        cout<<i<<" ";
    }
    return 0;
}