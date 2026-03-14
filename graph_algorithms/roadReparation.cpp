#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n);
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a-1].push_back({b-1,w});
        adj[b-1].push_back({a-1,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    vector<bool> visited(n,false);
    pq.push({0,0});
    
    long long ans = 0;
    int count = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int dist = it.first;
        int u = it.second;
        if(visited[u]) continue;
        visited[u] = true;
        ans+= dist;
        count++;
        for(auto next: adj[u]){
            int v = next.first;
            int d = next.second;
            if(!visited[v]){
                pq.push({d,v});
            }
        }
    }
    if(count != n) cout<<"IMPOSSIBLE"<<endl;
    else cout<<ans<<endl;
    return 0;
}