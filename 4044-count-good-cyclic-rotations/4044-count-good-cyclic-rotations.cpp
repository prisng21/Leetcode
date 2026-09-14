class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int ans =0;

        int i = 0;
        int n = nums.size();
        long long first_half=0;
        long long last_half = 0;

        for(int i=0 ; i<n/2 ; i++){
            first_half += nums[i];
             last_half += nums[i+(n/2)] ;
        }
        if(first_half>last_half) ans++;



            

        int j = 0;
        int k= n/2;
        int check = n ;
        while(check-1>0){
            first_half = first_half - nums[j]+ nums[(j+(n/2))%n];
            last_half = last_half - nums[k%n] + nums[(k+(n/2))%n];

            if(first_half>last_half){
                ans++;
            }
            j++;
            k++;   
            check--;
        }     
        return ans;
    }
};