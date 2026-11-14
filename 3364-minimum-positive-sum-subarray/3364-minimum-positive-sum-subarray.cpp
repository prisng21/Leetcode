class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        int n = nums.size();

        for(int i =0 ; i<n ; i++){
            int sum = 0;
            int index=0;
            for(int j = i ; j<n ; j++){
                index = index+1;
                sum = sum + nums[j];

                if(index >=l && index <= r){
                    if( sum>0){
                        ans = min(sum , ans);
                    }
                }

            }
        }
        return ans == INT_MAX ? -1 : ans;
        
        
    }
};