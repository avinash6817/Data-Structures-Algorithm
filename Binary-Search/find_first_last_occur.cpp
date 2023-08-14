#include <bits/stdc++.h>
using namespace std;

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

int LowerBound(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0,high = n-1;
        int ans = n;

        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
}

int UpperBound(vector<int> &nums, int target){
    int n = nums.size();
    int low = 0,high = n-1;
    int ans = n;

    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> ans;
    int n = nums.size();

    int lb = LowerBound(nums,target);
    if(lb == n || nums[lb] != target) return {-1,-1};

    int ub = UpperBound(nums,target);

    return {lb,ub-1};
}

int main(){
    vector<int> arr = {5,7,7,8,8,10};
    int target = 6;

    vector<int> ans = searchRange(arr,target);
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}
