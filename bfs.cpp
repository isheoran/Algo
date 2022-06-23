#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;

void bfs(int s) {
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        s = q.front();
        q.pop();
        if(vis[s]) continue;
        cout<<s<<" ";
        vis[s] = true;
        for(auto u:adj[s]) {
            q.push(u);
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
        if(!vis[i])  bfs(i);
    }
}