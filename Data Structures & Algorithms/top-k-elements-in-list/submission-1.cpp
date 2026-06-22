class Solution {
public:
    typedef pair<int,int> pp;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        // 1 -> 1, 2 -> 2, 3 -> 3, k = 2;
        // hashmap we will get freq and push
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(auto m: mp){
            pq.push({m.second,m.first});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
