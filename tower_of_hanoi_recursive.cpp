#include <iostream>
using namespace std;

void solve(int n,char from_rod,char aux_rod,char to_rod) {
    if(n==0) return;

    solve(n-1,from_rod,to_rod,aux_rod);
    cout<<"Move Disk "<<n<<" from rod "<<from_rod<<" to "<<to_rod<<"\n";
    solve(n-1,aux_rod,from_rod,to_rod);
}

int main() {
    // Let Rods be named A,B,C
    int n;
    cin>>n;
    solve(n,'A','B','C');
    return 0;
}