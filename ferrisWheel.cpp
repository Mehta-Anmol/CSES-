#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    
    sort(nums.begin(),nums.end());
    int count = 0;
    int i = 0;
    int  j = n-1;
    while(i <= j){
        if(i == j){
            count++;
            i++;
            j--;
            continue;
        }
        if(nums[i]+nums[j] <= k){
            count++;
            i++;
            j--;
        }
        else{
            count++;
            j--;
        }
    }
    cout<<count<<endl;
    return 0;
}