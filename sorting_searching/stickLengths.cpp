#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int mid;
    if(n%2 == 0){
        mid = (n/2)-1;
    }
    else{
        mid = (n-1)/2;
    }
    int num = nums[mid];
    long long ans = 0;
    for(int i=0;i<n;i++){
        ans+= (abs(nums[i]-num));
    }
    cout<<ans<<endl;
    return 0;

}