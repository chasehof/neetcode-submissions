class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        auto it = std::max_element(piles.begin(), piles.end());

        int max_k = *it;

        int i{1};
        int j{max_k};

        int ret{h};

        while(i <= j){
            int mid = std::midpoint(i, j);
            if(time_to_eat(mid, piles) <= h){
                j = mid - 1;

                ret = mid;
            }
            else{

                i = mid + 1;

            }

        }

        return ret;
        
    }

    int time_to_eat(int k, std::vector<int>& piles){
        int time{};
        
        for(const auto pile : piles){
            auto res = std::div(pile, k);
            time += res.quot + (res.rem != 0);
        }


        return time;
    }
};





