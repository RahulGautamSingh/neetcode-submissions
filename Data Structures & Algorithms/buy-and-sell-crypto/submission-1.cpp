class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1,maxP=0,len=prices.size();
        while(r<len){
            if(prices[r] > prices[l]){
                maxP = max(prices[r] - prices[l], maxP);
            }else {
                l = r;
            }

            r++;
        }

        return maxP;
    }
};
