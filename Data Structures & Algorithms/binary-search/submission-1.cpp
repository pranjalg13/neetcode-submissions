class Solution {
public:
    int binarySearch(int low, int high, vector<int>& nums, int target){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target == nums[mid]) return mid;
            else if(target > nums[mid]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(0,nums.size(),nums,target);
    }
};
