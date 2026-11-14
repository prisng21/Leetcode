class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt_inc = 1;
        int cnt_dec = 1;
        int max_cnt_inc = 1;
        int max_cnt_dec = 1;

        for(int i = 1 ; i< n ; i++){

            if(nums[i]>nums[i-1]){
                cnt_inc++;
                cnt_dec = 1;
                max_cnt_inc = max(max_cnt_inc ,cnt_inc );

            }
            else if(nums[i]<nums[i-1]){
                cnt_inc=1;
                cnt_dec++;
                max_cnt_dec = max(max_cnt_dec ,cnt_dec );

            } 

            else{
                cnt_dec=1;
                cnt_inc=1;

            }           




        }

        return max(max_cnt_inc , max_cnt_dec);
        
    }
};