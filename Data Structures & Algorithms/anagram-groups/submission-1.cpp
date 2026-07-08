class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<std::string, std::vector<std::string>> hash{};

        std::vector<std::vector<std::string>> vec{};
        vec.reserve(strs.size());

        for(const auto& str : strs){
            std::string sorted {str.begin(), str.end()};
            
            std::sort(sorted.begin(), sorted.end());

            hash[sorted].push_back(std::move(str));
        }


        for(const auto& [key, value] : hash){
            vec.push_back(std::move(value));
        }

        return vec;
        
    }
};
