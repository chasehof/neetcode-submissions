class Solution {
public:
    bool isPalindrome(string s) {
        std::string temp{};

        for(char c : s){
            if(std::isalnum(c)){
                temp.push_back(std::tolower(c));
            }
        }

        std::string not_reversed = temp;

        std::reverse(temp.begin(), temp.end());

        if(temp == not_reversed){
            return true;
        }

        return false;
    }
};
