class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(n^2) and O(1) 2 for loop solution
        // O(n) O(n)

        //nums = [3,4,5,6], target = 7
        // target - arr[i] exists
        unordered_map<int,int> mp;
        int size  = nums.size();
        vector<int> ans(2);
        for(int i=0;i<size;i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]], i};
            }
            mp[nums[i]] = i;
        }
        return ans;

        // One More Variant 2 count as well

    }
};
