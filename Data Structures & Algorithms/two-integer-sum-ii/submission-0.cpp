class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        size_t i{0};

        size_t j{numbers.size() - 1};

        while(numbers[i] + numbers[j] != target){
            if(numbers[i] + numbers[j] > target){
                j--;
            }
            else{
                i++;
            }
        }

        return {static_cast<int>(i + 1), static_cast<int>(j + 1)};


        
    }
};
