#include <bits/stdc++.h>
using namespace std;
#define sz(vec) (int)(vec.size())

const long long inf = 1e18;

struct DSU {
    vector<int>sizz,parent;

    DSU(){}

    DSU(int n) {
        for(int i=0;i<=n;i++) {
            sizz.push_back(1);
            parent.push_back(i);
        }
    }

    void reset(int n) {
        sizz.assign(n+1,1);
        for(int i=0;i<=n;i++) {
            parent[i] = i;
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

    bool operator==(const Edge &o) const {
        return (a==o.a and b==o.b and w==o.w);
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
    
    long long cost = inf;
    vector<Edge>second_best_mst;

    for(auto u:MST) {
        G.reset(n);
        vector<Edge>new_tree;
        for(auto edge:edges) {
            if(edge==u or G.find_set(edge.a)==G.find_set(edge.b)) continue;
            new_tree.push_back(edge);
            G.union_set(edge.a,edge.b);
        }

        if(sz(new_tree)!=n-1) continue;

        long long cst = 0;
        for(auto edge:new_tree) {
            cst += edge.w;
        } 

        if(cst < cost) {
            second_best_mst = new_tree;
            cost = cst;
        }
    }

    if(cost < inf) {
        cout<<"Cost of second best mst is "<<cost<<"\n";
        cout<<"Edges of the second best mst are : \n";
        Print_edges(second_best_mst);
    }
    else {
        cout<<"Sorry ! No second best mst exists.\n";
    }

    return 0;
}