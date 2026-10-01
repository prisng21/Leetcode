// class Solution {
// public:
//     bool isValid(string s) {
//         vector<char> stack;

//         for (char c : s) {
//             if (c == '(' || c == '{' || c == '[') {
//                 stack.push_back(c);  // push opening bracket
//             } else {
//                 // if stack is empty, there's no matching opening bracket
//                 if (stack.empty()) return false;

//                 char top = stack.back(); // get last opening bracket
//                 // check if it matches the current closing bracket
//                 if ((c == ')' && top == '(') ||
//                     (c == '}' && top == '{') ||
//                     (c == ']' && top == '[')) {
//                     stack.pop_back(); // valid match, remove opening bracket
//                 } else {
//                     return false; // mismatch
//                 }
//             }
//         }

//         // if stack is empty, all brackets matched
//         return stack.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(int i=0 ; i<s.size() ; i++){

            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }else{

                if(st.empty()) return false;

                else if(s[i]==')'){
                    if(st.top()!='(') return false;
                    else{
                        st.pop();
                    }
                }
                else if(s[i]=='}'){
                    if(st.top()!='{') return false;
                    else{
                        st.pop();
                    }
                }
                else if(s[i]==']'){
                    if(st.top()!='[') return false;
                    else{
                        st.pop();
                    }
                }                                
            }
            
        }
        if(st.empty()) return true ;
        else{
            return false;
        }
    }
};    



// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> st;
//         for(char val: s){
//             if(val=='(' || val=='{' || val=='['){
//                 st.push(val);
//             }
//             else{
//                 if(st.empty()){
//                     return false;
//                 }
//                 if((st.top()=='(' && val==')') || (st.top()=='{' && val=='}') || (st.top()=='[' && val==']')){
//                     st.pop();
//                 }
//                 else{
//                     return false;
//                 }
//             }
//         }
//         return st.empty();
//     }
// };
