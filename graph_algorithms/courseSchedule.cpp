#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }

        }
    }
    bool check = true;
    for(int i=1;i<=n;i++){
        if(indegree[i] > 0){
            cout<<"IMPOSSIBLE"<<endl;
            check = false;
            break;
        }
    }
    if(check){
        for(auto it: ans){
            cout<<it<<" ";
        }
    }
    cout<<endl;
    return 0;
}