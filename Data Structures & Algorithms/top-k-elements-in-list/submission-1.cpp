class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> hash{};

        std::vector<int> ret{};

        ret.reserve(k);
        
        for(int num : nums){
            hash[num]++;
        }

        std::vector<std::pair<int, int>> sort{hash.begin(), hash.end()};

        std::nth_element(sort.begin(), sort.begin() + k,  sort.end(), [](const auto a, const auto b){
            return b.second < a.second;
        });

        for(int i = 0; i < k; i++){
            ret.push_back(sort[i].first);
        }


        return ret;




    }
};
