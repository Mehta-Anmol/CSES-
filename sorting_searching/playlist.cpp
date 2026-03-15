#include<bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    map<int,int> mpp;
    int ans = 0;
    int i = 0;
    for(int j=0;j<n;j++){
        mpp[nums[j]]++;\
        while(i < j && mpp[nums[j]] > 1){
            mpp[nums[i]]--;
            if(mpp[nums[i]] == 0){
                mpp.erase(nums[i]);
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}