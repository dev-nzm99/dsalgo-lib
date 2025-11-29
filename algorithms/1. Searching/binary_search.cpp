/*find the position(1-based indexing) at which k is present in the
array using binary search.*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> binarySearch(vector<int> &arr, int key){
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    int i = 0; // iteration counter

    while (left <= right){
        ++i;
        int mid = left + (right - left) / 2; // safe mid

        if (arr[mid] == key)
            return {mid + 1, i}; // 1-based position
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return {-1, i}; // not found, -1 as position
}

int main(){
    vector<int> arr = {2, 3, 4, 10, 33, 40};
    int k = 10;
  
    pair<int, int> res = binarySearch(arr, k);

    if (res.first != -1){ // ✅ check index, not whole pair
        cout << "Element present at position " << res.first << '\n';
        cout << "Total iteration : " << res.second << '\n';
    }else
        cout << "Element not found!" << '\n';
    return 0;
}
