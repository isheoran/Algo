#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;

void dfs(int s) {
    stack<int>st;
    st.push(s);
    while(!st.empty()) {
        s = st.top();
        st.pop();
        
        if(vis[s]) continue;
        cout<<s<<" ";
        vis[s] = true;
        for(auto u:adj[s]) {
            st.push(u);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    vis.assign(n+1,false);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i])  dfs(i);
    }
}