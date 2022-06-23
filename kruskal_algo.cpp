#include <bits/stdc++.h>
using namespace std;
#define sz(vec) (int)(vec.size())

struct DSU {
    vector<int>sizz,parent;

    DSU(){}

    DSU(int n) {
        for(int i=0;i<=n;i++) {
            sizz.push_back(1);
            parent.push_back(i);
        }
    }

    int find_set(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find_set(parent[x]);
    }

    void union_set(int u,int v) {
        int leader_u = find_set(u);
        int leader_v = find_set(v);

        if(u==v) return ;

        if(sizz[leader_u] > sizz[leader_v]) {
            sizz[leader_v] += sizz[leader_u];
            parent[leader_u] = leader_v;
        }
        else {
            sizz[leader_u] += sizz[leader_v];
            parent[leader_v] = leader_u;
        }
    }
};

struct Edge {
    int a,b,w;

    Edge(){}

    Edge(int a,int b,int w) {
        this->a = a;
        this->b = b;
        this->w = w;
    }

    bool operator<(const Edge &o)const {
        return w < o.w;
    }

    void print() {
        cout<<a<<' '<<b<<' '<<w<<"\n";
    }
};

void Print_edges(vector<Edge>&edges) {
    for(auto u:edges) {
        u.print();
    }
}

int main() {
    
    int n,m;
    cin>>n>>m;

    vector<Edge>edges;

    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(Edge(u+1,v+1,w));
    }

    sort(edges.begin(),edges.end());

    vector<Edge>MST;

    DSU G(n);

    for(const auto &edge:edges) {
        if(G.find_set(edge.a) != G.find_set(edge.b)) {
            G.union_set(edge.a, edge.b);
            MST.push_back(edge);
        }
    } 

    if(sz(MST)!=n-1) {
        cout<<"We can not create spanning tree with given edges\n";
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