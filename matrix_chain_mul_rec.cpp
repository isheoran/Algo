#include <bits/stdc++.h>
using namespace std;
vector<int>p;
const int inf = 1e9;

int func(int l,int r) {
    if(l >= r-1) {
        return 0;
    }
    int res = inf;
    for(int i=l+1;i<r;i++) {
        res = min(res,func(l,i)+p[l]*p[i]*p[r]+func(i,r));
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    p.resize(n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    cout<<func(0,n-1)<<endl;
    return 0;
}