class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() < 1) {return 0;}

        int max{0};
        int count{0};

        std::unordered_set<char> seen{};


        int i{0};
        int j{0};


        while(j < s.length()){
            auto inserted = seen.insert(s[j]).second;

            if(inserted){
                count++;
                max = std::max(count, max);
                j++;
            }
            else{
                seen.erase(s[i]);
                i++;
                count--;
            }
        }


        return max;
        
    }
};
