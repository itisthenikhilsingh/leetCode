class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n = prices.size();
         int ans = 0;
         int minSofar=prices[0];
         for(int i=0;i<n;i++)
         {
            minSofar=min(minSofar,prices[i]);
            int temp= prices[i]-minSofar;

            ans= max(ans, temp);

         }
         return ans;
        
    }
};