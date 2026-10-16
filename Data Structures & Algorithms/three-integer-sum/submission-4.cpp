class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        std::ranges::sort(nums);



        vector<vector<int>> ans{};
        int seen{std::numeric_limits<int>::max()};

        for(int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            std::cout << seen << " " << nums[i] << '\n';

            if(seen == nums[i]) {continue;}

            while(j < k){
                // std::cout << nums[i] << " "  << nums[j] << " " << nums[k] << '\n';
                // std::cout << nums[i] + nums[j] + nums[k] << '\n';
                if(nums[j] + nums[k] == -nums[i]){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    
                    j++;
                    while(nums[j] == nums[j - 1]){
                        if(j == nums.size() - 1) {break;}
                        j++;
                    }
                    
                }
                else if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else {
                    j++;
                }
            }

            seen = nums[i];
        }


        return ans;
        
    }
};


// nums = [-1,0,1,2,-1,-4]

// nums = [-4, -1, -1, 0, 1, 2]




// nums = [0,1,1]



// nums = [0,0,0]