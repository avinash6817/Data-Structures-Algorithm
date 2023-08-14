#include <bits/stdc++.h>
using namespace std;

// Input: arr = [4, 4, 8, 8, 8, 15, 16, 23, 23, 42], target = 8
// Output: 3

int no_of_occur_sorted_arr(vector<int> &arr,int target){
    // (last occurence) - (first occurence) + 1
    int lb = lower_bound(arr.begin(),arr.end(),target) - arr.begin();
    int ub = upper_bound(arr.begin(),arr.end(),target) - arr.begin();

    return ub - lb;
}

int main(){
    vector<int> arr = {4, 4, 8, 8, 8, 15, 16, 23, 23, 42};
    int target = 42;

    cout<<no_of_occur_sorted_arr(arr,target)<<endl;

    return 0;
}
