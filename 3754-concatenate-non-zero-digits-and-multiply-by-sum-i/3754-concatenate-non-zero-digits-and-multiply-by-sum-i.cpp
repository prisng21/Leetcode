class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num  = 0 ;
        long long sum =0; ;

        while(n>0){
            int rem = n%10;
            sum = sum+rem;

            if(rem !=0){
                num = num*10 + rem ;
            }
            n=n/10;
        }
        long long x= 0;

        while(num>0){
            int rem  = num%10;
            x= x*10 + rem;
            num =num/10;
        }

        long long ans = x * sum;
        return ans;
        
    }
};