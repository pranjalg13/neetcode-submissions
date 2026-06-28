class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 1 2 8 48
        // 48 48 24 6
        // i -> (i-1) * (j + 1)
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        vector<int> ans(n);
        int temp = 1;
        for(int i=0;i<n;i++){
            temp = temp * nums[i];
            prefix[i] = temp;
        }
        temp = 1;
        for(int i=n-1;i>=0;i--){
            temp = temp * nums[i];
            suffix[i] = temp;
        }
        for(int i=0;i<n;i++){
            if(i == 0) ans[i] = suffix[i+1];
            else if(i==n-1) ans[i] = prefix[n-2];
            else ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};
