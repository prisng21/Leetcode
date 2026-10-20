class Solution {
public:
    int minInsertions(string s) {
        int ans=0;
        int cnt=0 ;
        int n = s.size();
        int i=0;

        while(i<n){
            if(s[i] == '('){
                cnt++;
                i++;
            }
            else if(s[i] == ')'){
                   if(cnt>0){
                    if(s[i+1]==')'){
                        cnt--;             // remove
                        i=i+2;
                    }
                    else{
                        ans++;
                        i++;
                        cnt--;
                    }

                }else{
                    ans++;                 // add '('
                    
                    if(s[i+1]==')'){
                        i=i+2;


                    }else{
                        ans++;      // add '('
                        i++;

                    }
                }


            }
        }
        return ans+cnt*2;
        
    }
};