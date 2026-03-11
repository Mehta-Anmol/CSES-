#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> desire(n);
    for(int i=0;i<n;i++){
        cin>>desire[i];
    }
    vector<int> apsize(m);
    for(int i=0;i<m;i++){
        cin>>apsize[i];
    }
    int count = 0;
    sort(desire.begin(),desire.end());
    sort(apsize.begin(),apsize.end());
    for(int i=0,j=0;i<n && j<m;){
        if(desire[i] < apsize[j]-k){
            i++;
        }
        else if(desire[i] > apsize[j]+k){
            j++;
        }
        else{
            i++;
            j++;
            count++;
        }
    }
    cout<<count<<endl;
    
    
    return 0;
}