#include <bits/stdc++.h>
using namespace std;

int main() {

    int n,m;
    cin>>n>>m;

    string a,b; 
    cin>>a>>b; 

    vector<vector<int>>dp(n+1,vector<int>(m+1));
    //dp[i][j] represents lcs of a[0:i-1] and b[0:j-1]

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    string lcs;

    int i = n , j = m;
    while(i>0 and j>0) {
        if(a[i-1] == b[j-1]) {
            lcs.push_back(a[i-1]);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse(lcs.begin(),lcs.end());

    cout<<"Length of lcs is : "<<dp[n][m]<<endl;
    cout<<"LCS is : "<<lcs;

    return 0;
}