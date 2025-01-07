class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0;i<prices.size()-1;i++)
        {
            int dif=prices[i+1]-prices[i];
            if(dif>0) profit+=dif; 
        }
        return profit;
        
    }
};