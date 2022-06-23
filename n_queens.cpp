#include <bits/stdc++.h>
using namespace std;
#define sz(v) (int)(v.size())

bool is_safe(vector<vector<bool>>&board,int r,int c) {
    for(int i=0;i<c;i++) {
        if(board[r][i]) return false;
    }
    for(int i=r,j=c;i>=0 and j>=0;i--,j--) {
        if(board[i][j]) return false;
    }
    for(int i=r,j=c;i<sz(board) and j>=0;i++,j--) {
        if(board[i][j]) return false;
    }
    return true;
}

bool solve(vector<vector<bool>>&board,int col) {
    
    if(col == sz(board)) return true;
    for(int i=0;i<sz(board);i++) {
        if(is_safe(board,i,col)) {
            board[i][col] = true;

            if(solve(board,col+1)) {
                return true;
            }

            board[i][col] = false;
        }
    }

    return false;
}

int main() {
    int n;
    cin>>n;

    vector<vector<bool>>board(n,vector<bool>(n,false));
    
    if(solve(board,0)) {
        cout<<"Following is a valid solution : \n";
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else {
        cout<<"Solution does not exist for this configuration.\n";
    }

    return 0;
}