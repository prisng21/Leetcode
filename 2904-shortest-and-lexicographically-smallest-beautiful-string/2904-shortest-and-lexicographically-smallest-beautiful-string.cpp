class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0; 
        int j = 0;
        int cnt = 0;
        int mini = INT_MAX;
        int start = 0;
        int end = 0;
        string ans;

        while (j < n) {

            // Add current character
            if (s[j] == '1') {
                cnt++;
            }

            // When we have k ones
            while (cnt == k) {

                // Remove unnecessary leading zeros
                while (i <= j && s[i] == '0') {
                    i++;
                }

                int len = j - i + 1;

                string curr = s.substr(i, len);

                // Shorter substring OR lexicographically smaller
                if (len < mini || (len == mini && curr < ans)) {
                    start = i;
                    end = j;
                    mini = len;
                    ans = curr;
                }

                // Remove the first '1'
                if (s[i] == '1') {
                    cnt--;
                    i++;
                }
            }

            j++;
        }

        return ans;
    }
};

// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         int n = s.length();
//         int i = 0 ; 
//         int j= 0 ;
//         int cnt =0 ;
//         int mini =INT_MAX;
//         int start = 0;
//         int end = 0;
//         string ans;

//         while(j<n){


//             if(cnt >=k){
//                 while(cnt<k){
//                      if(s[j]=='1'){
//                         cnt --;
//                          i++;
//                     }else{
//                         i++;
//                     }
//                     if(mini>cnt){
//                         start = i;
//                         end  = j;
//                         mini = min(mini , cnt);

//                     }
                    
//                 }
//             }
//             else{
//                 if(s[j]== '1'){
//                     cnt++;
//                     j++;
//                 }else{
//                     j++;
//                 }
//             }
//         }
//         for(int  i = start ; i<=end ; i++){
//             ans = ans+s[i];
//         }
//         return ans;
        
//     }
// };