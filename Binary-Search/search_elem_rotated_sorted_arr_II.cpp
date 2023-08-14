#include <bits/stdc++.h>
using namespace std;

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false

// For duplicate elements
bool search_rotated_arr(vector<int> &arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            return true;
        }
        // For duplicate adding the conditions
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
            continue;
        }

        // checking in the left sorted part
        if(arr[low] <= arr[mid]){
            // checking target lies in this sorted part or not
            if(arr[low] <= target && target <= arr[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // checking in the right sorted part
        else{
            // checking target lies in this sorted part or not
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }

    return false;
}

int main(){
    vector<int> arr = {2,5,6,0,0,1,2};
    int target = 0;

    bool res = search_rotated_arr(arr,target);
    cout<<res<<endl;

    return 0;
}