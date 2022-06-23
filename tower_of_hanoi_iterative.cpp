#include <iostream>
#include <stack>
using namespace std;

void tower_of_hanoi(int n) {
    stack<pair<int,string>>s;
    s.push(make_pair(n,"ABC"));
    while(!s.empty()) {
        auto u = s.top();
        s.pop();
        if(u.first<0) {
            cout<<"Move Disk "<<-u.first<<" from rod "<<u.second[0]<<" to "<<u.second[2]<<"\n";
        }
        else if(u.first) {
            swap(u.second[0],u.second[1]);
            s.push(make_pair(u.first-1,u.second));
            swap(u.second[1],u.second[0]);
            s.push(make_pair(-u.first,u.second));
            swap(u.second[2],u.second[1]);
            s.push(make_pair(u.first-1,u.second));
        }
    }
}

int main() {
    // Let Rods be named A,B,C
    int n;
    cin>>n;
    tower_of_hanoi(n);

    return 0;
}