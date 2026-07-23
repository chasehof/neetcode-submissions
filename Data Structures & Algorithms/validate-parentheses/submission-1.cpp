class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stck{};
        if(s[0] == '}' || s[0] == ')' || s[0] == ']'){
            return false;
        }


        for(char x : s){
            if(x == '{' || x == '(' || x == '['){
                stck.push_back(x);
            }
            else{
                if(!stck.empty()){
                char comp = stck.back();
                stck.pop_back();

                if(comp == '(' && x != ')' || comp == '{' && x != '}' || comp == '[' && x != ']' ){
                    return false;
                }
                }
                else{
                    return false;
                }
                

            }
        }

        if(!stck.empty()){
            return false;
        }


        return true;
    }
};

