class Solution {
public:
    int topdowndp(int n, vector<int> &dp){
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = topdowndp(n-1,dp) + topdowndp(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return topdowndp(n,dp);
    }
};
