#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1), rev(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    vector<bool> vis(n+1,false);

    dfs(1,adj,vis);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<1<<" "<<i<<"\n";
            return 0;
        }
    }

    fill(vis.begin(), vis.end(), false);

    dfs(1,rev,vis);

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout<<"NO\n";
            cout<<i<<" "<<1<<"\n";
            return 0;
        }
    }

    cout<<"YES\n";
}