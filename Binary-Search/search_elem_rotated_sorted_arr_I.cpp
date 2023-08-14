#include <bits/stdc++.h>
using namespace std;

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// For unique elements
int search_rotated_arr(vector<int> &arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] == target){
            return mid;
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

    return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 3;

    cout<<search_rotated_arr(arr,target)<<endl;

    return 0;
}