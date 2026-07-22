class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,minprice=INT_MAX;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            minprice=min(minprice,prices[i]);
            int profit=prices[i]-minprice;
            maxprofit=max(profit,maxprofit);
        
        }
        return maxprofit;
    }
};