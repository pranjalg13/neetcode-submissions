class Solution {
public:
    int topDownDp(int n, vector<int> &cost, vector<int> &dp){
        if(n == 0 || n == 1) return 0;
        if(dp[n] != -1) return dp[n];
        int one = topDownDp(n - 1, cost, dp) + cost[n-1];
        int two = INT_MAX;
        if(n > 1)
            two = topDownDp(n - 2, cost, dp) + cost[n-2];
        return dp[n] = min(one, two);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return topDownDp(n, cost, dp);
    }
};
