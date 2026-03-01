#include<bits/stdc++.h>
using namespace std;

int func(int n){
    int count = 0;
    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            count++;
            if(i != n/i){
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        cout<<func(k)<<endl;
    }
    return 0;
}