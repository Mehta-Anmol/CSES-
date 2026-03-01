#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& visited){
    visited[i] = true;
    for(auto it: adj[i]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans;

    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(visited[i] == false){
            dfs(i,adj,visited);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<endl;
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
    return 0;

}