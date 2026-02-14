#include<bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    long long n;
    cin>>n;
    vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
        int a,d;
        cin>>a>>d;
        nums.push_back({a,1});
        nums.push_back({d,-1});
    }
    sort(nums.begin(),nums.end());
    int curr = 0;
    int maxi = 0;
    for(auto& e: nums){
        curr+= e.second;
        maxi = max(maxi,curr);
    }
    cout<<maxi<<endl;
    return 0;
}
