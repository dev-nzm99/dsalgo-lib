// Problem: Search Insert Position
// Find the index where the target should be inserted in a sorted array.

int searchInsert(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;                // Target found at mid
        }
        else if (nums[mid] < target) {
            left = mid + 1;            // Move right
        }
        else {
            right = mid - 1;           // Move left
        }
    }
    // At the end, 'left' is the correct insertion index
    return left;
}
