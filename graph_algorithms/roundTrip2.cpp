#include<bits/stdc++.h>
using namespace std;
 
void solve(int sv, int ev,vector<int>& parent){
    vector<int> ans;
    ans.push_back(sv);
 
    for(int v = ev; v != sv; v = parent[v]){
        ans.push_back(v);
    }
 
    ans.push_back(sv);
 
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<endl;
}
 
bool dfs(int i, int& sv,int& ev, vector<vector<int>>& adj, vector<int>& state,vector<int>& parent){
    state[i] = 1;
    for(auto next:adj[i]){
        if(state[next] == 0){
            parent[next] = i;
            if(dfs(next,sv,ev,adj,state,parent)){
                return true;
            }
        }
        else if(state[next] == 1){
            sv = next;
            ev = i;
            return true;
        }
    }
    state[i] = 2;
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
    }
    int sv =0;
    int ev = 0;
    vector<int> state(n+1,0);
    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(state[i] == 0){
            if(dfs(i,sv,ev,adj,state,parent)){
                solve(sv,ev,parent);
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}