// class Solution {
// public:
//     string reverseParentheses(string s) {

//         stack<char>st;
//         int n = s.size();
//         int i =0;

//         while(i<n){
            
//             while(i<n && s[i]!=')'){
//                 st.push(s[i]);
//                 i++;
//             }
//             i++;

//             bool check = true;
//             vector<int>temp;
//             while(check == true){
//                 if(st.top()=='('){
//                     st.pop();
//                     check=false;
//                     break;

//                 }
                
//                 temp.push_back(st.top());
//                 st.pop();
//             }
//             // for(int j=0;j<temp.size();j++){
//             //     st.push(temp[j]);

//             // }
//             for(int j=temp.size()-1;j>=0;j--){
//              st.push(temp[j]);
//             }

             
//         }
//         string ans = "";

//         while(!st.empty()){
//             ans =ans+st.top();
//             st.pop();
//         }
//         // reverse(ans.begin(), ans.end());

//         return ans;

                
//     }
// };

class Solution {
public:
    string reverseParentheses(string s) {

        stack<char> st;
        int n = s.size();
        int i = 0;

        while(i < n) {

            if(s[i] != ')') {
                st.push(s[i]);
                i++;
            }
            else {
                i++;

                vector<char> temp;

                while(!st.empty() && st.top() != '(') {
                    temp.push_back(st.top());
                    st.pop();
                }

                if(!st.empty())
                    st.pop();

                for(char ch : temp) {
                    st.push(ch);
                }
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};