class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        std::unordered_set<char> seen{};

        int i{0};
        int j{0};
        int max{0};

        while(j < s.size()){
            bool inserted = seen.insert(s[j]).second;
            if(inserted){
                max = std::max(max, j - i + 1);
                j++;
            }
            else{
                seen.erase(s[i]);
                i++;
            }
        }


        return max;
        
    }
};
