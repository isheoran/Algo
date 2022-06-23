#include<iostream>
using namespace std;

void swap(int *a,int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[],int l,int r) {
    int pivot = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++) {
        if(arr[j]<pivot) swap(&arr[++i],&arr[j]);
    }
    swap(&arr[++i],&arr[r]);
    return i;
}

void quickSort(int arr[],int l,int r) {
    if(l>=r) return;
    int stack[r-l+1];
    int top = -1;
    stack[++top] = l;
    stack[++top] = r;
    while(top>=0) {
        r = stack[top--];
        l = stack[top--];
        int p = partition(arr,l,r);
        if(p-1>l) {
            stack[++top] = l;
            stack[++top] = p-1;
        }
        if(p+1<r) {
            stack[++top] = p+1;
            stack[++top] = r;
        }
    }
}

int main() {
    int arr[10];
    for(int i=0;i<10;i++) {
        cin>>arr[i];
    }
    quickSort(arr,0,9);
    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}