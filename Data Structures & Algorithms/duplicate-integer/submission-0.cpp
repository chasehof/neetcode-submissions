class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for(const auto& num : nums){
            if(std::count(nums.begin(), nums.end(), num) > 1){
                return true;
            }
        }

        return false;
    }
};