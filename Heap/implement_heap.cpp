#include <bits/stdc++.h>
using namespace std;

/* Implementing Heap --(Max-Heap) with the help of Array */

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1; // for implementing 1 based indexing
            size = 0;
        }

        void insert(int val){
            size = size + 1;
            int index = size;

            // step-1: insert at the end of the Array
            arr[index] = val;


            // step-2: Take it to its correct position
            while(index > 1){
                int parent = index/2;

                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void deleteFromHeap(){
            if(size == 0){
                cout<<"Nothing to delete"<<endl;
                return;
            }

            // step-1: swap the firstNode(root) with the last node
            int temp = arr[1];
            arr[1] = arr[size];

            // step-2: remove the last node
            arr[size] = -1;
            cout<<"Node "<<temp<<" is deleted from the Heap"<<endl;
            size--;

            // step-3: Now propagate root node to its correct position
            int i = 1;

            while(i < size){
                int leftIndex = 2*i;
                int rightIndex = 2*i + 1;

                if(leftIndex <= size && arr[i] < arr[leftIndex]){
                    swap(arr[i],arr[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex <= size && arr[i] < arr[rightIndex]){
                    swap(arr[i],arr[rightIndex]);
                    i = rightIndex;
                }
                else{
                    return;
                }
            }

        }

        
};

int main(){
    Heap h;

    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);

    h.insert(55);
    h.insert(70);

    int n = 7;

    for(int i = 0;i <= n;i++){
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;

    h.deleteFromHeap();
    h.deleteFromHeap();

    for(int i=0;i <= n;i++){
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}