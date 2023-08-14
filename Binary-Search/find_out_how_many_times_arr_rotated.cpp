#include <bits/stdc++.h>
using namespace std;

// Input: arr[] = {15, 18, 2, 3, 6, 12}
// Output: 2
// Explanation: Initial array must be {2, 3, 6, 12, 15, 18}. 
// We get the given array after rotating the initial array twice.


// Input: arr[] = {7, 9, 11, 12, 5}
// Output: 4

// contains only unique elements 
int minm_rotated_sorted_arr_index(vector<int> &arr){
    int low = 0;
    int high = arr.size() - 1;
    int index = 0;
    int ans = INT_MAX; 

    while(low <= high){
        int mid = (low+high)/2;

        // left sorted part
        if(arr[low] <= arr[mid]){
            if(arr[low] < ans){
                index = low;
                ans = arr[low];
            }
            low = mid+1;
        }
        // Right sorted part
        else{
            if(arr[mid] < ans){
                index = mid;
                ans = arr[mid];
            }
            high = mid-1;
        }
    }

    return index;
}

int main(){
    // vector<int> arr = {15, 18, 2, 3, 6, 12};
    vector<int> arr = {7, 9, 11, 12, 5};

    cout<<minm_rotated_sorted_arr_index(arr)<<endl;

    return 0;
}