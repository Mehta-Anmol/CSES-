#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;
    cin>>n>>m;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<ll> prefix(n);
    prefix[0] = nums[0];
    for(int i=1;i<n;i++){
        prefix[i] = nums[i]+prefix[i-1];
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        if(a == 1){
            cout<<prefix[b-1]<<endl;
        }
        else{
            cout<<prefix[b-1]-prefix[a-2]<<endl;
        }
        
    }
    return 0;
    
    
}