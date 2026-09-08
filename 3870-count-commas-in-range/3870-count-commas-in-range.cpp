class Solution {
public:
    int countCommas(int n) {
        int cnt  = 0;
        int num =n;

        while(num>0){
            num=num/10;
            cnt++;

        }

        if(cnt<=3){
            return 0;
        }
        else{
            return n-999;
        }
        
    }
};