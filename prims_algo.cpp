#include <bits/stdc++.h>
using namespace std;
#define sz(vec) (int)(vec.size())

struct Edge {
    int a,b,w;

    Edge(){}

    Edge(int a,int b,int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }

    bool operator<(const Edge &o) const {
        return w > o.w;
    }

    void print() {
        cout<<a<<' '<<b<<' '<<w<<"\n";
    }
};

vector<Edge> Prims (vector<vector<pair<int,int>>>&adj,int n) {
    vector<Edge>edges;

    priority_queue<Edge>q;
    vector<bool>vis(n+1);
    vis[1] = true;
    for(auto u:adj[1]) {
        q.push(Edge(1,u.first,u.second));
    }

    while(!q.empty()) {
        auto s = q.top();
        q.pop();
        if(vis[s.b]) continue;
        vis[s.b] = true;
        edges.push_back(s);

        for(auto u:adj[s.b]) {
            q.push(Edge(s.b,u.first,u.second));
        }
    }

    return edges;
}

void Print_edges(vector<Edge>&edges) {
    for(auto u:edges) {
        u.print();
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++) {
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    vector<Edge> MST = Prims(adj,n);

    if(sz(MST)!=n-1) {
        cout<<"We can not spanning tree with given edges\n";
        return 0;
    }

    long long min_cost = 0;

    for(const auto &u:MST) {
        min_cost += u.w;
    }
    
    cout<<"Minimum cost of our spanning tree is : \n";
    cout<<min_cost<<"\n";

    cout<<"Following is MST :\n";
    Print_edges(MST);

    return 0;
}