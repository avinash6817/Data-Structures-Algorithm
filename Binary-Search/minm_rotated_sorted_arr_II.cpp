#include <bits/stdc++.h>
using namespace std;

// Input: nums = [2,2,2,0,1]
// Output: 0

// contains duplicate elements
int minm_rotated_sorted_arr(vector<int> &arr){
    int minm = INT_MAX;
    int n = arr.size();
    int low = 0,high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            minm = min(minm,arr[low]);
            low = low + 1;
            high = high - 1;
            continue;
        }
        // left sorted array
        if(arr[low] <= arr[mid]){
            minm = min(minm,arr[low]);
            low = mid + 1;
        }
        // right sorted array
        else{
            minm = min(minm,arr[mid]);
            high = mid - 1;
        }
    }

    return minm;
}

int main(){
    vector<int> arr = {2,2,2,-2,0,1};
    // vector<int> arr = {3,4,5,1,2};

    cout<<minm_rotated_sorted_arr(arr)<<endl;

    return 0;
}