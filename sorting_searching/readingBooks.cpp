#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    long long sum = 0;
    for(int i=0;i<n-1;i++){
        sum+= nums[i];
    }

    if(nums[n-1] > sum){
        cout<<2*nums[n-1]<<endl;
    }
    else{
        cout<<sum+nums[n-1]<<endl;
    }
    return 0;

}