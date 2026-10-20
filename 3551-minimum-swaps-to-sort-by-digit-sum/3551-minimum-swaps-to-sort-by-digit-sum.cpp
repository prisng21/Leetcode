// class Solution {
// public:
// int getDigitsum(int n){
//     int sum = 0 ;
//     while(n>0){
//         int rem = n%10;
//         sum+=rem;
//         n=n/10;
//     }
//     return sum;
// }
//     int minSwaps(vector<int>& nums) { 
//         int n = nums.size();
//         vector<int>aftersorted(nums);

//         auto lambda = [](int nums1  , int num2){
//             int digitsum1 = getDigitsum(num1);
//             int digitsum2 = getDigitsum(num2);

//             if(digitsum1 !=digitsum2){
//                 return  digitsum1<digitsum2;

//             }
//             return num1<num2;


//         }

//         sort(begin(aftersorted) , end(aftersorted) , lambda);

//         unordered_map<int ,int>val_to_idx;

//         for(int i =0;i<n ; i++){
//             val_to_idx[nums[i]]=1;
//         }

//         int swapCnt = 0;

//         for(int i = 0 ; i<n ; i++){
//             int expectedVal = aftersorted[i];
//             int currVal = nums[i];


//             if(expectedVal = currVal){
//                 continue;
//             }else{
//                 int idx = val_to_idx[expectedVal]; 
//                 nums[i] = expectedVal;
//                 nums[idx] = currVal;

//                 val_to_idx[expectedVal] = i;
//                 val_to_idx[currVal] = idx;
//                 swapCnt++;
                


//             }
//             return swapcount;

//         }
//     }



// };



class Solution {
public:
    int getDigitsum(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += rem;
            n = n / 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> aftersorted(nums);

        auto lambda = [&](int num1, int num2) {
            int digitsum1 = getDigitsum(num1);
            int digitsum2 = getDigitsum(num2);

            if (digitsum1 != digitsum2) {
                return digitsum1 < digitsum2;
            }
            return num1 < num2;
        };

        sort(begin(aftersorted), end(aftersorted), lambda);

        unordered_map<int, int> val_to_idx;

        for (int i = 0; i < n; i++) {
            val_to_idx[nums[i]] = i;
        }

        int swapCnt = 0;

        for (int i = 0; i < n; i++) {
            int expectedVal = aftersorted[i];
            int currVal = nums[i];

            if (expectedVal == currVal) {
                continue;
            } else {
                int idx = val_to_idx[expectedVal];

                nums[i] = expectedVal;
                nums[idx] = currVal;

                val_to_idx[expectedVal] = i;
                val_to_idx[currVal] = idx;

                swapCnt++;
            }
        }

        return swapCnt;
    }
};
