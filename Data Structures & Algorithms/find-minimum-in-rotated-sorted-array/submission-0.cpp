class Solution {
public:
    int findMin(vector<int> &nums) {
        int high{static_cast<int>(nums.size())};
        int low{};

        int ans{nums[low]};


        while(high >= low){
            int mid = std::midpoint(low, high);

            if(std::is_sorted(nums.begin() + low, nums.begin() + high)){
                return ans;

            }
            else{
                if(std::is_sorted(nums.begin(), nums.begin() + mid)){
                    low = mid;
                    ans = nums[mid];
                }
                else{
                    high = mid;
                    ans = nums[mid];
                }
            }
            
            

        }


        return 0;
    }
};


 

//     [2, 0, 1]


//     [0,1 ,2]




// [7, 8, 9 10, 0, 1, 2, 3]