
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();

        vector<long long> countDiff(1e5 + 1, 0);

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }

        long long K = 1LL * k1 + k2;

        for (int currDiff = 1e5; currDiff > 0 && K > 0; currDiff--) {
            long long countOps = min(countDiff[currDiff], K);

            countDiff[currDiff] -= countOps;
            countDiff[currDiff - 1] += countOps;

            K -= countOps;
        }

        long long result = 0;

        for (int d = 1; d <= 1e5; d++) {
            result += 1LL * countDiff[d] * d * d;
        }

        return result;
    }
};





// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

//         vector<int>temp;
//         int n = nums1.size();

//         for(int i =0 ; i<n ; i++){
//             int diff= abs(nums1[i] - nums2[i]);
//             temp.push_back(diff);
//         }

//         sort(temp.begin() , temp.end());

//         while(k1>0 || k2>0){
//             if(k1>0){
//                 if(temp[n-2]temp[n-1]){
//                     temp[n-1]
//                 }
//             }
//         }

//         int ans =0;
//         for(int i=0 ; i<n ;i++){
//             ans = ans+temp[i]*temp[i];
//         }
//         return ans;
        
//     }
// };




// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         vector<int> temp;
//         int n = nums1.size();

//         for (int i = 0; i < n; i++) {
//             int diff = abs(nums1[i] - nums2[i]);
//             temp.push_back(diff);
//         }

//         sort(temp.begin(), temp.end());

//         long long k = 1LL * k1 + k2;

//         while (k > 0 && temp[n - 1] > 0) {
//             temp[n - 1]--;

//             sort(temp.begin(), temp.end());
//             k--;
//         }

//         long long ans = 0;

//         for (int i = 0; i < n; i++) {
//             ans += 1LL * temp[i] * temp[i];
//         }

//         return ans;
//     }
// };




// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         vector<long long> temp;
//         int n = nums1.size();

//         for (int i = 0; i < n; i++) {
//             temp.push_back(abs(nums1[i] - nums2[i]));
//         }

//         sort(temp.begin(), temp.end(), greater<long long>());

//         long long k = 1LL * k1 + k2;

//         for (int i = 0; i < n && k > 0; i++) {
//             long long next = (i + 1 < n ? temp[i + 1] : 0);
//             long long count = i + 1;
//             long long need = (temp[i] - next) * count;

//             if (need <= k) {
//                 for (int j = 0; j <= i; j++) {
//                     temp[j] = next;
//                 }
//                 k -= need;
//             } else {
//                 long long dec = k / count;
//                 long long rem = k % count;

//                 for (int j = 0; j <= i; j++) {
//                     temp[j] -= dec;
//                     if (j < rem) temp[j]--;
//                 }

//                 k = 0;
//             }
//         }

//         long long ans = 0;
//         for (long long x : temp) {
//             ans += x * x;
//         }

//         return ans;
//     }
// };
