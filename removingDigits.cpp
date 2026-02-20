#include<bits/stdc++.h>
using namespace std;

int func(int n, vector<int>& dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];

    int temp = n;
    int ans = INT_MAX;

    while(temp > 0){
        int digit  = temp%10;
        temp/= 10;
        if(digit != 0){
            ans = min(ans,1+func(n-digit,dp));
        }
    }
    return dp[n] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    vector<int> dp(n+1,-1);

    cout<<func(n,dp)<<endl;
    return 0;
}