#include <bits/stdc++.h>
using namespace std;

// Smallest index such that --> arr[ind] > target
int impl_upper_bound(vector<int> &arr,int target,int n){
    int low = 0;
    int high = n-1;
    int ans = n; // initialise to imaginary index if lower bound does not exist. 

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] > target){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,5,8,8,10,10,11};
    int n = arr.size();
    int target = 10;

    cout<<impl_upper_bound(arr,target,n)<<endl;

    return 0;
}