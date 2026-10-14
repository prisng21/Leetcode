
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<int> positive;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int pos = -1 * nums[i];
                positive.push_back(pos);
            }
            else {
                positive.push_back(nums[i]);
            }
        }

        sort(positive.begin(), positive.end());
        int n = positive.size();

        int left = 0;
        int right = n - 1;

        long long ans = 0;  // Changed int to long long

        while (left <= right) {
            if (right >= left) {
                ans += 1LL * positive[right] * positive[right];
                right--;
            }

            if (right >= left) {
                ans -= 1LL * positive[left] * positive[left];
                left++;
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     long long maxAlternatingSum(vector<int>& nums) {
//         vector<int>postive ;

//         for(int i=0 ;i<nums.size(); i++){
//             if(nums[i]<0){
//                 int pos = -1 * nums[i];
//                 postive.push_back(pos);
//             }
//             else{
//                 postive.push_back(nums[i]);
//             }
//         }

//         sort(postive.begin() , postive.end());
//         int n = postive.size();

//         int left  = 0;
//         int right = n-1;

//         int ans =0;

//         while(left<=right){

//             if(right>=left){

//             ans = ans + postive[right] * postive[right] ;
//             right --;
//             }

//            if(right>=left){

//             ans = ans - postive[left] * postive[left] ;
//             left++;
//             }

//         }
//         return ans;

        

         

        
//     }
// };