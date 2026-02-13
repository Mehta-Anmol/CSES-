#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin>>n;
    long long den = 5;
    long long ans = 0;
    while(den <= n){
        ans+= n/den;
        den*=5;
    }
    cout<<ans<<endl;
    return 0;
}