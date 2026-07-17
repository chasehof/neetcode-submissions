class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i {0};

        int j {1};
        int max{0};


        while(j < prices.size()){
            if(prices[j] < prices[i]){
                i = j;

                j++;
            }
            else{

                max = std::max(max, prices[j] - prices[i]);
                j++;
            }
        }


        if(max < 0){
            return 0;
        }

        return max;
        
    }
};
