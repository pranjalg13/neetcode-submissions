class Solution {
public:
    bool isAllBananasPossible(int h, vector<int>& piles, int ele){
        int sum = 0;
        for(auto pile: piles){
            if(ele > pile) sum += 1;
            else sum += ceil((double)pile/ele);
        }
        cout<<sum<<endl;
        if(sum > h) return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxx = *max_element(piles.begin(),piles.end());
        int low = 1, high = maxx;
        int ans = INT_MAX;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(isAllBananasPossible(h,piles,mid)){
                ans = min(ans, mid);
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;

    }
};
