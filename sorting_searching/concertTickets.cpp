#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,m;
    cin>>n>>m;
    multiset<int> st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    while(m--){
        int x;
        cin>>x;
        auto it = st.upper_bound(x);
        if(it == st.begin()){
            cout<<-1<<endl;
        }
        else{
            it = prev(it);
            cout<<*it<<endl;
            st.erase(it);
        }
    }
    return 0;
}