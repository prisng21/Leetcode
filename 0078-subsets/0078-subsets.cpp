class Solution {
public:
    vector<vector<int>>ans;

    void solve(vector<int>& nums , int idx , vector<int>&temp)
{
    if(idx>=nums.size()){
        ans.push_back(temp);
        return;
    }

    temp.push_back(nums[idx]);
    solve(nums, idx+1 , temp);

    temp.pop_back();
    solve(nums,idx+1 , temp);






}


    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int>temp;
        solve(nums,0 ,temp);
        return ans;
        
    }
};





// class Solution {
// public:
//     // Function to generate all subsets (the power set) of the input array
//     vector<vector<int>> subsets(vector<int>& nums){
//         // Get the size of the input array
//         int n = nums.size();

//         // Calculate the total number of subsets (2^n) using bitwise shift
//         int subsets = 1 << n;

//         // Vector to store all subsets
//         vector<vector<int>> ans;

//         // Iterate through all numbers from 0 to 2^n - 1
//         for (int num = 0; num < subsets; num++) {
//             // Temporary vector to hold the current subset
//             vector<int> subset;

//             // Iterate through each bit of the number
//             for (int i = 0; i < n; i++) {
//                 // If the ith bit is set, include nums[i] in the subset
//                 if (num & (1 << i)) {
//                     subset.push_back(nums[i]);
//                 }
//             }

//             // Add the constructed subset into the result
//             ans.push_back(subset);
//         }

//         // Return all subsets
//         return ans;
//     }
// };



// class Solution {
// public:

// void subseq( vector<int>& nums , int index , int N ,vector<vector<int>>&ans , vector<int>&temp ){

//     // base condition 
//     if(index==N){
//         ans.push_back(temp);
//         return ;
//     }



//     //  // number nhi liya

//     subseq( nums, index+1 , N , ans , temp );   

//     // number le  liya
//     temp.push_back(nums[index]);
//     subseq( nums, index+1 , N , ans , temp );
//     temp.pop_back();

// }


//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>>ans;
//         vector<int>temp;
//         subseq(nums , 0 , nums.size() , ans , temp);
//         return ans; 

        
//     }
// };





// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> result;

//         for(int bits = 0; bits < (1ll << n); bits++) {
//             vector<int> curr;
//             for(int i = 0; i < n; i++) {
//                 if(bits & (1ll<<i)) {
//                     curr.push_back(nums[i]);
//                 }
//             }
//             result.push_back(curr);
//         }

//         return result;
//     }
// };