#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
char dc[4] = {'R','L','D','U'};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    vector<string> lab(n);
    for(int i=0;i<n;i++){
        cin>>lab[i];
    }

    int sx = -1, sy = -1, ex = -1, ey = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(lab[i][j] == 'A'){
                sx = i;
                sy = j;
            }
            if(lab[i][j] == 'B'){
                ex = i;
                ey = j;
            }
        }
    }

    queue<pair<int,pair<int,int>>> q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> dir(n,vector<int>(m,-1));

    q.push({0,{sx,sy}});
    visited[sx][sy] = true;

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int dist = it.first;
        int x = it.second.first;
        int y = it.second.second;

        if(x == ex && y == ey){

            cout<<"YES"<<endl;
            cout<<dist<<endl;

            string path;

            while(x!=sx || y!=sy){
                int k = dir[x][y];
                path.push_back(dc[k]);
                x -= dx[k];
                y -= dy[k];
            }

            reverse(path.begin(),path.end());
            cout<<path<<endl;

            return 0;
        }

        for(int k=0;k<4;k++){
            int nx = x+dx[k];
            int ny = y+dy[k];

            if(nx >=0 && ny >=0 && nx < n && ny < m && lab[nx][ny] != '#' && !visited[nx][ny]){
                visited[nx][ny] = true;
                dir[nx][ny] = k;
                q.push({dist+1,{nx,ny}});
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}