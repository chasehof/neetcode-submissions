class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left{};
        int most_frequent_elem{};
        int ret{};
        std::array<int, 26> freq_list{};

        for(int right = 0; right < s.size(); right++){
            freq_list[s[right] - 'A']++;

            most_frequent_elem = std::max(most_frequent_elem, freq_list[s[right] - 'A']);

            if((right - left + 1) - most_frequent_elem > k){
                
                freq_list[s[left] - 'A']--;
                left++;
            }

            ret = std::max(ret, (right - left + 1));


        }

        return ret;
    }
};
