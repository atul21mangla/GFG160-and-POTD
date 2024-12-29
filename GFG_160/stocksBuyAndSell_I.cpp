// TC - O(N)
// SC - O(1)
// problem link - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int minSoFar = 1e9;
        int profit = 0;
        for(int i=0;i<n;i++){
            if(prices[i]<minSoFar){
                minSoFar = prices[i];
            }
            profit = max(profit,prices[i]-minSoFar);
        }
        return profit;
    }
};


// brute force
// TC - O(N*2)
// SC - O(1)

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int res = 0;
  
        // Explore all possible ways to buy and sell stock
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, prices[j] - prices[i]);
            }
        }
        return res;
    }
};
