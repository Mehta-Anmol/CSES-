#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin>>n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++){
        cin>>nums[i];
    }
    multiset<ll> st;
    for(auto x: nums){
        auto it = st.upper_bound(x);
        if(it != st.end()){
            st.erase(it);
        }
        st.insert(x);
    }
    cout<<st.size()<<endl;
    return 0;

}