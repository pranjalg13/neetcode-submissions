class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int len = 0;
                while(st.find(nums[i]++)!=st.end()){
                    len++;
                }
                ans = max(len, ans);
            }
        }
        return ans;
    }
};
