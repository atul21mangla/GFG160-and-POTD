//  https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/stock-buy-and-sell2615
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
  public:
  
    int solve(vector<int> &prices , int n , int idx , int buy , 
     vector<vector<int>>& dp){
         
         // Base Case
         if(idx==n){
             return 0;
         }
         if(dp[idx][buy]!=-1)return dp[idx][buy];
         
         int profit = 0;
         if(buy){
             profit = max(-prices[idx] + solve(prices,n,idx+1,0,dp),
                0 + solve(prices,n,idx+1,1,dp));
         }
         else{  // trying to sell - sell or not sell
             profit = max(prices[idx] + solve(prices,n,idx+1,1,dp),
             0 + solve(prices,n,idx+1,0,dp));
         }
         return dp[idx][buy] = profit;
     }
  
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return solve(prices,n,0,1,dp);

      // Tabulation Solution
      // TC - O(n) with constant space 
        int aheadBuy = 0 , aheadNotBuy = 0;
        int currBuy = 0 , currNotBuy = 0;
        for(int ind = n-1;ind>=0;ind--){
            currBuy = max(-prices[ind] + aheadNotBuy , 
            0 + aheadBuy);
            
            currNotBuy = max(prices[ind] + aheadBuy,
            0 + aheadNotBuy);
            
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
    }
};


// Local minima maxima approach

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = prices[0];  // Local Minima
    int lMax = prices[0];  // Local Maxima
    int res = 0;
  
    int i = 0;
    while (i < n - 1) {
      
        // Find local minima 
        while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
        lMin = prices[i];
       
        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
        lMax = prices[i];
      
        // Add current profit 
        res = res + (lMax - lMin);
    }
  
    return res;
}

// Accumulate profit Approach

int maximumProfit(const vector<int>& prices) {
    int res = 0;
  
    // Keep on adding the difference between
    // adjacent when the prices a
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) 
            res += prices[i] - prices[i - 1];
    }
    
    return res;
}
