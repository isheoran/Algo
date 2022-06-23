#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main() {
    int n;
    cin>>n;
    vector<int>p(n);
    
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }

    vector<vector<int>>dp(n,vector<int>(n,inf));

    for(int i=0;i<n;i++) {
        dp[i][i] = 0;
        if(i!=n-1) dp[i][i+1] = 0;
    }

    for(int l=3;l<=n;l++) {
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int k = i + l -1;
                if(k<=j or k>=n) continue;
                dp[i][k] = min(dp[i][k],dp[i][j]+p[i]*p[j]*p[k]+dp[j][k]);
            }
        }
    }

    cout<<dp[0][n-1];

    return 0;
}