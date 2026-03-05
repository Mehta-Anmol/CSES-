#include<bits/stdc++.h>
using namespace std;

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
    vector<int> colors(n+1,0);
    for(int i=1;i<=n;i++){
        if(colors[i] == 0){
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto next: adj[node]){
                    if(colors[next] == 0){
                        colors[next] = 3-colors[node];
                        q.push(next);
                    }
                    else if(colors[next] == colors[node]){
                        cout<<"IMPOSSIBLE"<<endl;
                        return 0;
                    }
                }
            }
            
        }
    }
    for(int i=1;i<=n;i++){
        cout<<colors[i]<<" ";
    }
    return 0;

    
}