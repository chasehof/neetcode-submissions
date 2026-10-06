class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        int i{};
        int j{static_cast<int>(s1.size() - 1)};

        std::unordered_map<int, int> ascii_map{};

        for (auto cha : s1) {
            ascii_map[static_cast<int>(cha)]++;
        }

        std::unordered_map<int, int> ascii_map_s2{};

        for (int x = i; x <= j; x++) {
            ascii_map_s2[static_cast<int>(s2[x])]++;
        }

        while (j < s2.size()) {
            bool broke_out{false};
            for (const auto& [ascii, count] : ascii_map) {
                if (ascii_map_s2.find(ascii) != ascii_map_s2.end()) {
                    if (count == ascii_map_s2[ascii]) {
                        if (broke_out == false) {
                            continue;
                        }
                    } else {
                        broke_out = true;
                    }
                } else {
                    broke_out = true;
                }
            }

            if (broke_out == false) {
                return true;
            }

            if(j == s2.size() - 1){break;}

            int remove = static_cast<int>(s2[i]);
            ascii_map_s2[remove]--;
            i++;

                        j++;
            int add = static_cast<int>(s2[j]);
            ascii_map_s2[add]++;
        }

        return false;
    }
};
