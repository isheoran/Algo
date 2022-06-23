#include <bits/stdc++.h>
using namespace std;
#define sz(v) (int)(v.size())

int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

bool is_valid(int x,int y) {
    if(x<0 or x>=4 or y<0 or y>=4) return false;
    return true;
}

int cost(vector<vector<int>>board) {
    int res = 0,cnt = 1;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(i == 3 and j==3) continue;
            res += (board[i][j] != cnt++);
        }
    }
    res += board[3][3] != 0;
    return res;
}

struct Data {
    int cost;
    vector<vector<int>>board;
    vector<vector<vector<int>>>pre_boards;

    Data(){};

    Data(int cost,vector<vector<int>>board) {
        this->cost = cost;
        this->board = board;
        pre_boards.clear();
    }

    bool operator<(const Data &o) const {
        return cost > o.cost;
    }
};

int main() {
    
    vector<vector<int>>board(4,vector<int>(4));
    Data ans;

    int operations = 0;
    const int max_operations = 1e5;

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            cin>>board[i][j];
        }
    }

    priority_queue<Data>q;

    q.push(Data(cost(board),board));

    while(!q.empty()) {
        Data cur = q.top();
        q.pop();

        if(cost(cur.board) == 0) {
            ans = cur;
            ans.pre_boards.push_back(cur.board);
            break;
        }

        int x = -1,y = -1;
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                if(cur.board[i][j] == 0) {
                    x = i;
                    y = j;
                }
            }
        }
        
        for(int i=0;i<4;i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if(is_valid(new_x,new_y)) {
                Data tmp = cur;
                swap(tmp.board[new_x][new_y],tmp.board[x][y]);
                tmp.pre_boards.push_back(cur.board);
                tmp.cost = cost(tmp.board)+sz(cur.pre_boards);
                q.push(tmp);
            }
        }

        if(max_operations < operations++) {
            cout<<"No valid moves exist to reach goal state.\n";
            return 0;
        }
    }

    for(int k=0;k<sz(ans.pre_boards);k++) {
        for(int i=0;i<4;i++) {
            for(int j=0;j<4;j++) {
                cout<<ans.pre_boards[k][i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }

    return 0;
}