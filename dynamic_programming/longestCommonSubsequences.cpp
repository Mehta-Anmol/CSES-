#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> s(n), t(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i = n,j=m;
    vector<int> lcs;
    while(i > 0 && j > 0){
        if(s[i-1] == t[j-1]){
            lcs.push_back(s[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    cout<<lcs.size()<<endl;
    for(auto it: lcs){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}