#include <bits/stdc++.h>
using namespace std;

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

// contains only unique elements 
int minm_rotated_sorted_arr(vector<int> &arr){
    int low = 0;
    int high = arr.size() - 1;
    int minm = INT_MAX;

    while(low <= high){
        int mid = (low+high)/2;

        // left sorted part
        if(arr[low] <= arr[mid]){
            minm = min(minm,arr[low]);
            low = mid+1;
        }
        // Right sorted part
        else{
            minm = min(minm,arr[mid]);
            high = mid-1;
        }
    }

    return minm;
}

int main(){
    vector<int> arr = {3,4,5,1,2};

    cout<<minm_rotated_sorted_arr(arr)<<endl;

    return 0;
}