#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
    long long n;
    cin>>n;
    long long sum =0;
    for(int i=1;i<=n;i++){
        sum+= i;
    }
    if(sum%2 != 0){
        cout<<"NO"<<endl;
        return 0;
    }
    long long target = sum/2;
    vector<long long> a;
    vector<long long> b;
    
    for(long long i=n;i>=1;i--){
        if(i <= target){
            a.push_back(i);
            target-= i;
            
        }
        else{
            b.push_back(i);
        }
    }
    cout<<"YES"<<endl;
    cout<<a.size()<<endl;
    for(int i: a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<b.size()<<endl;
    for(int i: b){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
    
    
    
}