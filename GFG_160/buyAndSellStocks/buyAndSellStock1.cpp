// Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// problem link - https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/problem/buy-stock-2

// TC - O(N)
// SC - O(1)

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



// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.
