#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int> parent,size;
    int components;
    int maxSize;

    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        components = n;
        maxSize = 1;
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(parent[x] == x) return parent[x];
        return parent[x] = findParent(parent[x]);
    }

    void unite(int a,int b){
        int pa = findParent(a);
        int pb = findParent(b);

        if(pa == pb) return;
        if(size[pa] < size[pb]) swap(pa,pb);

        parent[pb] = pa;
        size[pa]+= size[pb];
        components--;
        maxSize = max(maxSize,size[pa]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        dsu.unite(a,b);
        cout<<dsu.components<<" "<<dsu.maxSize<<endl;
    }
    return 0;
}