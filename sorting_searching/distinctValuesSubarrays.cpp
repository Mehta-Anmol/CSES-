#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];

    }
    ll count = 0;
    map<ll,ll> mpp;
    ll l = 0;
    for(ll r=0;r<n;r++){
        mpp[nums[r]]++;
        while(l < r && mpp[nums[r]] > 1){
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0){
                mpp.erase(nums[l]);
            }
            l++;
        }
        count+= (r-l+1);
    }
    cout<<count<<endl;
    return 0;
}