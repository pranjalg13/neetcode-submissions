class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        // Next Greater
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first <= temp[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top().second;
            }
            st.push({temp[i], i});
        }
        for (int i=0;i<n;i++){
            if(ans[i]!=0){
                ans[i] = ans[i] - i;
            }
        }
        return ans;
    }
};
