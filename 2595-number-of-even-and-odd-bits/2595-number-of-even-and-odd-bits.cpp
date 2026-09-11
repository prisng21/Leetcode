class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even=0;
        int odd = 0;
        int cnt =0;

        while(n>0){
            if(n&1==1){
                if(cnt%2 == 0){
                    even++;
                }else{
                    odd++;
                }
            }
            n>>=1;
            cnt++;
        }
        vector<int>ans;
        ans.push_back(even);
        ans.push_back(odd);

        return ans;
        
    }
};