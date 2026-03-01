#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back({b,1});
        adj[b].push_back({a,1});
    }
    vector<int> dist(n+1,1e8),parent(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto it: adj[u]){
            int v = it.first;
            int w = it.second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                parent[v] = u;
                pq.push({dist[v],v});
            }
        }
    }
    if(dist[n] == 1e8){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector<int> path;
    for(int v = n;v != -1;v = parent[v]){
        path.push_back(v);
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto it: path){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}