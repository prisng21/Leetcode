// class Solution {
// public:

//    int totalsum(vector<int>& nums ,int i , int temp_sum , int n ){

//     if(i>n){
//         ans= ans + temp_sum;

//     }

//     totalsum(vector<int>& nums , i+1 ; temp_sum + nums[i] , n )
//     totalsum(vector<int>& nums , i+1 ; temp + nums[i] , n );





//    }
//     int sumCounts(vector<int>& nums) {
//         int m = nums.size();

//         int result = totalsum(vector<int>& nums ,int i , int temp_sum , m );

        
//     }
// };





class Solution {
public:
    int ans = 0;

    void totalsum(vector<int>& nums, int i, int j) {
        if (i == nums.size()) return;

        if (j == nums.size()) {
            totalsum(nums, i + 1, i + 1);
            return;
        }

        unordered_set<int> st;

        for (int k = i; k <= j; k++) {
            st.insert(nums[k]);
        }

        ans += st.size() * st.size();

        totalsum(nums, i, j + 1);
    }

    int sumCounts(vector<int>& nums) {
        ans = 0;
        totalsum(nums, 0, 0);
        return ans;
    }
};