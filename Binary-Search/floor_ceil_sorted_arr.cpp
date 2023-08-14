#include <bits/stdc++.h>
using namespace std;

// floor --> largest num. in array <= target
int floor_val(vector<int> &arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] <= target){
            ans = arr[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }

    return ans;
}

// ceil --> smallest num. in array >= target
int ceil_val(vector<int> &arr,int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high){
        int mid = (low+high)/2;

        if(arr[mid] >= target){
            ans = arr[mid];
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr = {10,20,30,40,50};
    int target = 25;

    cout<<floor_val(arr,target)<<endl;
    cout<<ceil_val(arr,target)<<endl;

    return 0;
}
