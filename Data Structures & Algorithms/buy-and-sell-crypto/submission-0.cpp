class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<int> highest = {};
        highest.push_back(prices[len-1]);
        int highNow = prices[len - 1];

        for(int i=len-2; i>=0; i--){
            if(prices[i] > highNow) highNow = prices[i];
            highest.push_back(highNow);
        }

        reverse(highest.begin(), highest.end());

        int maxProfit = 0;

        for(int i=0;i<len-1;i++){
            int profitNow = highest[i] - prices[i];
            if(profitNow > maxProfit){
                maxProfit = profitNow;
            }
        }

        return maxProfit;
    }
};
