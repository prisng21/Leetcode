class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        
        //find smallest num if odd-true if even then -check all value must be even

        int mini =INT_MAX;



        for(int i =0 ; i<nums1.size() ;i++ ){
            mini = min(mini , nums1[i]);

        }

        if(mini%2!=0){
            return true;
        }
        else{
            int check_even = 1;
            for(int i =0 ; i<nums1.size() ;i++ ){
                if(nums1[i]%2!= 0){
                    check_even = 0;
                }
            }

            if(check_even ==0){
                return false;
            }else{
                return true;
            }

        }


        
    }
};