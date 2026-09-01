class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();
        int mini = INT_MAX;
        int idx_min =0;
        int maxi = INT_MIN;
        int idx_max =0;
        int ans =0;

        for(int i=0 ; i<n ;i++){

            if(mini > nums[i]){
                mini = nums[i];
                idx_min =i;
            }
            if(maxi < nums[i]){
                maxi = nums[i];
              idx_max =i;  
            }         
        }


        //delete from both side 
        int left=0;
         int right = 0;

        left = min(idx_min, idx_max);
        right = max(idx_min, idx_max);

        // if(idx_max > idx_min){
        //     idx_min = left;
        //     idx_max = right;
        // }else{
        //     idx_min = right;
        //     idx_max = left;;            
        // }

        int both_side = (left + 1) + (n-right) ;
        int left_side = right +1;
        int right_side = n - left;

        ans =  min({both_side,left_side,right_side});

        
        return ans;
    }
};