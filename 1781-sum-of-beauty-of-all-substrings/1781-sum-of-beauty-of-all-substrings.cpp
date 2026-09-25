
// // tc = n^3
// class Solution {
// public:

//     int solve(string &s , int i , int j){
//         unordered_map<char , int>mp;
//         for(int k=i ; k<=j ;k++){
//             mp[s[k]]++;
//         }

//         int maxi =INT_MIN;
//         int mini= INT_MAX;

//         for(auto it:mp){
//             if(it.second>maxi){
//                 maxi = it.second;
//             }
//             if(it.second<mini){
//                 mini = it.second;
//             }

//         }
//         return maxi-mini;

//     }
//     int beautySum(string s) {
//         int n = s.size();
//         int res = 0;

//         for(int i=0 ; i<n ; i++){
//             for(int j=i ; j<n;j++){
//                 res= res + solve(s , i , j);
                
//             }
//         }
//         return res;
        
//     }
// };

// TC = O(n^2)
// SC = O(1)  -> at most 26 characters

class Solution {
public:

    int solve(unordered_map<char, int>& mp) {

        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto it : mp) {
            if(it.second > maxi) {
                maxi = it.second;
            }

            if(it.second < mini) {
                mini = it.second;
            }
        }

        return maxi - mini;
    }

    int beautySum(string s) {
        int n = s.size();
        int res = 0;

        for(int i = 0; i < n; i++) {

            unordered_map<char, int> mp;

            for(int j = i; j < n; j++) {

                // Only add the newly included character
                mp[s[j]]++;

                res += solve(mp);
            }
        }

        return res;
    }
};