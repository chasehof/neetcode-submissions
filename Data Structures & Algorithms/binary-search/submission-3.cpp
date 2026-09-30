class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int i{0};
        int j{static_cast<int>(nums.size() - 1)};

        while (i <= j) {
            int mid = std::midpoint(i, j);
            if (target > nums[mid]) {
                i = mid + 1;
            } else if (target < nums[mid]) {
                j = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};

