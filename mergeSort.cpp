#include<iostream>
using namespace std;

void merge(int arr[],int l,int mid,int r) {
    if(mid==r) return;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a1[n1],a2[n2];
    for(int i=l;i<mid+1;i++) {
        a1[i-l] = arr[i];
    }
    for(int i=mid+1;i<r+1;i++) {
        a2[i-mid-1] = arr[i];
    }
    int i=0,j=0,idx=l;
    while(i<n1 and j<n2) {
        if(a1[i]>a2[j]) {
            arr[idx] = a2[j];
            j++;
        }
        else {
            arr[idx] = a1[i];
            i++;
        }
        idx++;
    }
    while(i<n1) {
        arr[idx] = a1[i];
        i++,idx++;
    }
    while(j<n2){
        arr[idx] = a2[j];
        idx++,j++;
    }
}

void mergeSort(int arr[],int n) {
    for(int cur_size = 1;cur_size<n;cur_size*=2) {
        for(int i=0;i<n;i+=2*cur_size) {
            int mid = min(i+cur_size-1,n-1);
            int r = min(n-1,i+2*cur_size-1);
            merge(arr,i,mid,r);
        }
    }
}

int main() {
    int arr[10];
    for(int i=0;i<10;i++) {
        cin>>arr[i];
    }
    mergeSort(arr,10);
    for(int i=0;i<10;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}