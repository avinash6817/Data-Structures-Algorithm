#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr,int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

void Heap_Sort(vector<int> &arr,int n){
    int size = n;

    while(size > 1){
        swap(arr[size],arr[1]);
        size--;

        heapify(arr,size,1);
    }
}

void display(vector<int> &arr,int n){
    for(int i = 0;i <= n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {-1,54,53,55,52,50,101};

    int n = arr.size() -1;

    // All other Nodes are Leaf Node
    for(int i=n/2;i > 0;i--){
        heapify(arr,n,i);
    }

    display(arr,n);

    Heap_Sort(arr,n);

    display(arr,n);
    


    return 0;
}