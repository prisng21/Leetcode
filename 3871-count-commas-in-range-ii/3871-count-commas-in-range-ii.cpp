class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;

        if(n <1000) return 0;

        long long lower  =1000;
        int comma = 1;

        while(lower<=n){
            long long check  = (lower*1000) - 1;
            long long  upper = min(check , n);

            long long count_num = upper - lower +1;
            result += count_num * comma; 

            lower  = lower*1000;
            comma++;
        }
        return result;
        
    }
};