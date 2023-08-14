#include <bits/stdc++.h>
using namespace std;

// just implement the lower Bound to find that index.
int search_insert_position(vector<int> &arr,int target,int n){
    int low = 0;
    int high = n-1;
    int ans = n; // initialise to imaginary index if lower bound does not exist. 

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[mid] >= target){
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
    vector<int> arr = {1,2,4,7};
    int n = arr.size();
    int target = 6;

    cout<<search_insert_position(arr,target,n)<<endl;

    return 0;
}
