#include<bits/stdc++.h>
using namespace std;

void solve(vector<pair<int,int>>& nums, int n,long long x){
    
    sort(nums.begin(),nums.end());
    for(int i=0;i<n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int l = j+1;
            int r = n-1;
            while(l < r){
                long long sum = (long long)nums[i].first+nums[j].first+nums[l].first+nums[r].first;
                if(sum == x){
                    cout<<nums[i].second<<" "<<nums[j].second<<" "<<nums[l].second<<" "<<nums[r].second<<endl;
                    goto done;
                }
                else if(sum > x){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    done:;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long x;
    cin>>n;
    cin>>x;
    vector<pair<int,int>> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back({num,i+1});
    }
    solve(nums,n,x);
    return 0;
}