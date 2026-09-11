class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans =0;
        for(int i =0 ; i< nums.size() ; i++){
            int val = nums[i];

            int cnt = 0;

            while(val>0){
                val=val/10;
                cnt++;
            }
            if(cnt%2==0){
                ans++; 
            }
        }
        return ans;
        
    }
};