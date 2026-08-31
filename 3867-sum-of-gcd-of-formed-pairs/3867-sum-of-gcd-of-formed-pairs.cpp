class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_gcd(n);

        int mx = 0;

        // Step 1: Calculate prefix maximum
        // Step 2: Calculate gcd(nums[i], prefix maximum)
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefix_gcd[i] = gcd(nums[i], mx);
        }

        // Step 3: Sort
        sort(prefix_gcd.begin(), prefix_gcd.end());

        // Step 4: Pair smallest with largest
        int i = 0;
        int j = n - 1;
        long long sum = 0;

        while (i < j) {
            sum += gcd(prefix_gcd[i], prefix_gcd[j]);
            i++;
            j--;
        }

        return sum;
    }
};