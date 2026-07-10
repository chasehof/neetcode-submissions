class Solution {
public:
    bool isPalindrome(string s) {

        std::string s_stripped{};

        for(char& c : s){
            if(std::isalnum(static_cast<unsigned char>(c))){
                s_stripped.push_back(std::tolower(c));
            }
        }

        std::string temp{s_stripped.rbegin(), s_stripped.rend()};

        std::cout << temp;

        if(temp == s_stripped){
            return true;
        }

        return false;
    }
};
