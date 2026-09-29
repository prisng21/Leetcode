class Solution {
public:

    vector<vector<int>> ans;

    void subseq(vector<int>& nums, int index, vector<int>& temp) {

        // base condition
        if(index >= nums.size()) {
            ans.push_back(temp);
            return;
        }

        // number le liya
        temp.push_back(nums[index]);       // take
        subseq(nums, index + 1, temp);     // explore
        temp.pop_back();

        // same elements ko skip karo
        int next = index + 1;
        while(next < nums.size() && nums[next] == nums[index]) {
            next++;
        }

        subseq(nums, next, temp);           // not take
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> temp;
        subseq(nums, 0, temp);

        return ans;
    }
};

// class Solution {
// public:

// vector<vector<int>>ans ;

// void subseq( vector<int>& nums , int index , vector<int>&temp ){

//     // base condition 
//     if(index>=nums.size()){
//         ans.push_back(temp);
//         return ;
//     }

       

//     // number le  liya
//     temp.push_back(nums[index]);       // take 
//     subseq( nums, index+1 , temp );    // explore
//     temp.pop_back();

//     subseq( nums, index+1 , temp );    // not take

// }


//      vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<int>temp;
//         subseq(nums , 0 , temp);
//         return ans; 

        
//     }
// };