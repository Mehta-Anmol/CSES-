#include<bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int,int> mpp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mpp[x]++;
    }

    long long ans = 1;
    for(auto it : mpp){
        ans = (ans * (it.second + 1)) % MOD;
    }

    ans = (ans - 1 + MOD) % MOD; // safe subtraction
    cout << ans << "\n";

    return 0;
}