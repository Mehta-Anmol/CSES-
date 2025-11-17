#include<bits/stdc++.h>
using namespace std;

int mod = 1000000007;

int main(){
    long long n;
    cin>>n;
    int ans = 1;
    
    while(n > 0){
        ans = (ans*2)%mod;
        n--;
    }
    cout<<ans<<endl;

}
    

