class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        int cnt = 0 ;
        set<int>ans;

        for(int i =0 ; i< n ; i++){
            for(int j = 0; j<n ; j++){
                for(int k =0 ; k<n ; k++){

                    if(digits[i]!=0 && digits[k]%2== 0 && i!=j && i!=k && j!=k){
                        int num = digits[i]*100 + digits[j]*10 + digits[k]; 
                        ans.insert(num);                       
                    }

                    

                }
            }
        }
        return vector<int>(ans.begin(), ans.end());

        
    }
};