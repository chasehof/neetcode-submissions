class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> hash{};
        std::vector<int> ret{};
        ret.reserve(k);

        for(int num : nums){
            hash[num]++;
        }

        std::vector<std::pair<int, int>> sorted_list{};

        for(const auto [key, value] : hash){
            sorted_list.push_back({value, key});
        }

        std::nth_element(sorted_list.begin(), sorted_list.begin() + k - 1,sorted_list.end(),  [](const auto a, const auto b){
            return b.first < a.first;
        });

        for(int i = 0; i < k; i++){
            ret.push_back(sorted_list[i].second);
        }

        return ret;
        
    }
};
