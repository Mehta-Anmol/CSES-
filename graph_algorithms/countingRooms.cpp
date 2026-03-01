#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void change(vector<string>& mat,int i, int j, int n, int m){
    mat[i][j] = '#';
    for(int k=0;k<4;k++){
        int x = i+dx[k];
        int y = j+dy[k];
        if(x >=0 && y >=0 && x < n && y < m && mat[x][y] == '.'){
            change(mat,x,y,n,m);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<string> mat(n);
    for(int i=0;i<n;i++){
        cin>>mat[i];
    }
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j] == '.'){
                count++;
                change(mat,i,j,n,m);
            }
        }
    }
    cout<<count<<endl;
    return 0;
}