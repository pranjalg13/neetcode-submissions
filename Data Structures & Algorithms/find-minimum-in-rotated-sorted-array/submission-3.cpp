class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        int minele = INT_MAX;
        while(low<=high){
            int mid = (low + high) / 2;
            if(nums[low] <= nums[mid]){
                minele = min(minele, nums[low]);
                low = mid + 1;
            }else {
                minele = min(minele, nums[mid]);
                high = mid - 1;
            }
        }
        return minele;
    }
};
