#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& nums, int n){
    vector<int> ans;
    stack<int> st;

    for(int i=1;i<=n;i++){
        while(!st.empty() && nums[st.top()-1] >= nums[i-1]){
            st.pop();
        }
        if(st.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<st.top()<<" ";
        }
        st.push(i);
    }
    cout<<endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    solve(nums,n);
    return 0;
}