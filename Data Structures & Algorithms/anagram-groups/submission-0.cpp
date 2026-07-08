class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        using AnagramLists = std::vector<std::vector<std::string>>;

        AnagramLists ret{};

        std::unordered_map<std::string, std::vector<std::string>> hash{};


        for(const auto& str : strs){

            std::string temp(str.begin(), str.end());
            std::sort(temp.begin(), temp.end());


            hash[temp].push_back(str);

        }

        for(const auto& [key, value] : hash){
            ret.push_back(value);
        }

        return ret;


    }
};
