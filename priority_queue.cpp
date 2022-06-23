#include <bits/stdc++.h>
using namespace std;

class Priority_queue {
    vector<int>heap;
    int n = -1;
    
    public:
    Priority_queue() {}
    
    private:
    int parent(int i) {
        return (i-1)/2;
    }

    int left_child(int i) {
        return 2*i+1;
    }

    int right_child(int i) {
        return 2*i+2;
    }

    void shift_up(int i) {
        while(i>0 and heap[parent(i)] < heap[i]) {
            swap(heap[i],heap[parent(i)]);
            i = parent(i);
        }
    }

    void shift_down(int i) {
        int max_idx = i;

        int l = left_child(i);
        if(l<=n and heap[l] > heap[i]) {
            max_idx = l;
        }

        int r = right_child(i);
        if(r<=n and heap[r] > heap[max_idx]) {
            max_idx = r;
        }

        if(max_idx!=i) {
            swap(heap[max_idx],heap[i]);
            shift_down(max_idx);
        }
    }

    public:

    void push(int val) {
        n++;
        heap.push_back(val);
        shift_up(n);
    }

    int top() {
        return heap[0];
    }

    bool empty() {
        return n==-1;
    }

    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        n--;
        shift_down(0);
    }

    int size() {
        return n+1;
    }
};

int main() {
    
    Priority_queue q;
    
    int n;
    cin>>n;

    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        q.push(x);
        cout<<q.top()<<" ";
    }

    cout<<"\n";

    q.pop();
    q.pop();

    cout<<q.top()<<"\n";

    cout<<q.size()<<"\n";

    return 0;
}