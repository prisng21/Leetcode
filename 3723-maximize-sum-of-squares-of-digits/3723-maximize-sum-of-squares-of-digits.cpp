// class Solution {
// public:
//     string maxSumOfSquares(int num, int sum) {
//         string ans ="";
//         int  target = sum;
//             if(sum<=9){
//                 ans = ans + to_string(sum);
//                 for(int i = 2;i<=num ; i++){
//                     ans = ans + to_string(0);

//                 }
//                 return ans;

//             }  

//         else{      
//         for(int i=0 ; i<num ; i++){

//                 if(target>9){
//                     target = target-9;
//                     ans= ans+to_string(9);

//                 }else{
//                     ans=ans+to_string(target);
//                     target = 0;

//                 }
//         }

//         if(target==0){
//             return ans;
//         }else{
//             return "";
 
//         }
//         }     
//     }
// };





// class Solution {
// public:
//     string maxSumOfSquares(int num, int sum) {
//         string ans = "";
//         int target = sum;

//         if (sum > 9 * num) {
//             return "";
//         }

//         if (sum <= 9) {
//             ans = ans + to_string(sum);

//             for (int i = 2; i <= num; i++) {
//                 ans = ans + to_string(0);
//             }

//             return ans;
//         }
//         else {
//             for (int i = 0; i < num; i++) {
//                 if (target >= 9) {
//                     target = target - 9;
//                     ans = ans + to_string(9);
//                 }
//                 else {
//                     ans = ans + to_string(target);
//                     target = 0;
//                 }
//             }

//             if (target == 0) {
//                 return ans;
//             }
//             else {
//                 return "";
//             }
//         }
//     }
// };
 




 
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans;
        ans.reserve(num);

        while (num--) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }

        if (sum > 0) return "";
        return ans;
    }
};
