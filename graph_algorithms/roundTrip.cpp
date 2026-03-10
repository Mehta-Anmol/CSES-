#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>& parent, int st, int ev){
    vector<int> ans;
    for(int v=ev;v != st;v = parent[v]){
        ans.push_back(v);
    }
    ans.push_back(st);
    ans.push_back(ev);
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}

bool dfs(int curr,int& st, int& ev, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& parent){
    visited[curr] = true;
    for(auto next: adj[curr]){
        
        
        if(!visited[next]){
            parent[next] = curr;
            if(dfs(next,st,ev,adj,visited,parent)){
                return true;
            }
        }
        else{
            if(next != parent[curr]){
                st = next;
                ev = curr;
                return true;
            }
        }
    }
    return false;
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
    vector<bool> visited(n+1,false);
    vector<int> parent(n+1,-1);
    int st=0;
    
    int ev = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            
            if(dfs(i,st,ev,adj,visited,parent)){
                solve(parent,st,ev);
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}