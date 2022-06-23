#include <bits/stdc++.h>
using namespace std;

int next_power_of_two(int n) {
    int res = 1;
    while(res<n) res*=2;
    return res;
}

vector<vector<int>> add(vector<vector<int>>a,vector<vector<int>>b) {
    int n = a.size();
    vector<vector<int>>ans(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans[i].push_back(a[i][j]+b[i][j]);
        }
    }
    return ans;
}

vector<vector<int>> subtract(vector<vector<int>>a,vector<vector<int>>b) {
    int n = a.size();
    vector<vector<int>>ans(n);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans[i].push_back(a[i][j]-b[i][j]);
        }
    }
    return ans;
}

vector<vector<int>> multiply(vector<vector<int>>a,vector<vector<int>>b) {
    int n = a.size();
    
    if(n==1) {
        a[0][0]*=b[0][0];
        return a;
    }

    vector<vector<int>>aa[4],bb[4],p[7];
    for(int i=0;i<4;i++) {
        aa[i].resize(n/2);
        bb[i].resize(n/2);
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<n/2 and j<n/2) {
                aa[0][i].push_back(a[i][j]);
                bb[0][i].push_back(b[i][j]);
            }
            else if(i<n/2) {
                aa[1][i].push_back(a[i][j]);
                bb[1][i].push_back(b[i][j]);
            }
            else if(j<n/2) {
                aa[2][i-n/2].push_back(a[i][j]);
                bb[2][i-n/2].push_back(b[i][j]);
            }
            else {
                aa[3][i-n/2].push_back(a[i][j]);
                bb[3][i-n/2].push_back(b[i][j]);
            }
        }
    }
    p[0] = multiply(aa[0],subtract(bb[1],bb[3]));
    p[1] = multiply(add(aa[0],aa[1]),bb[3]);
    p[2] = multiply(add(aa[2],aa[3]),bb[0]);
    p[3] = multiply(aa[3],subtract(bb[2],bb[0]));
    p[4] = multiply(add(aa[0],aa[3]),add(bb[0],bb[3]));
    p[5] = multiply(subtract(aa[1],aa[3]),add(bb[2],bb[3]));
    p[6] = multiply(subtract(aa[0],aa[2]),add(bb[0],bb[1]));
    
    vector<vector<int>>ans[4];
    ans[0] = add(p[4],add(p[3],subtract(p[5],p[1])));
    ans[1] = add(p[0],p[1]);
    ans[2] = add(p[2],p[3]);
    ans[3] = add(p[0],subtract(p[4],add(p[2],p[6])));

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i<n/2 and j<n/2) a[i][j] = ans[0][i][j];
            else if(i<n/2) a[i][j] = ans[1][i][j-n/2];
            else if(j<n/2) a[i][j] = ans[2][i-n/2][j];
            else a[i][j] = ans[3][i-n/2][j-n/2];
        }
    }
    
    return a;
}

void strassen_multiplication(vector<vector<int>>&a,vector<vector<int>>&b) {
    //a-> pxq and b-> rxs
    int p = a.size(),q = a[0].size(),r = b.size(),s = b[0].size();
    if(q!=r) {
        cout<<"These matrices can not be multiplied.\n";
        return;
    }

    int n = max({p,q,r,s});
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++) {
        a[i].resize(n);
        b[i].resize(n);
    }

    vector<vector<int>>ans = multiply(a,b);
    for(int i=0;i<p;i++) {
        for(int j=0;j<s;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
    
    int p,q,r,s;
    cin>>p>>q;
    vector<vector<int>>a(p);
    for(int i=0;i<p;i++) {
        for(int j=0;j<q;j++) {
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    }

    cin>>r>>s;
    vector<vector<int>>b(r);
    for(int i=0;i<r;i++) {
        for(int j=0;j<s;j++) {
            int x;
            cin>>x;
            b[i].push_back(x);
        }
    }

    strassen_multiplication(a,b);

    return 0;
}