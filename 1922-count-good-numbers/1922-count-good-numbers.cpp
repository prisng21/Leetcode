class Solution {
public:
   const int M = 1e9+7;
   int solve(long long a ,long long b){
    if(b==0){
        return 1;

    }

    long long half = solve(a,b/2);
    long long result = (half * half) % M;
    if(b%2==1){
        result =(result* a) % M;
    }
    return result;
    

   }

    int countGoodNumbers(long long n){

        long long  odd= n/2;
        long long   even = (n+1)/2;

        long long ans = (1LL * solve(4, odd) * solve(5, even)) % M;
        return ans ;






        
    }
};