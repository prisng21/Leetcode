class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {

        int ans = 0;
        int n = arr1.size();
        int m = arr2.size();

        for( int i =0 ; i<n ; i++){
            int val = arr1[i];

            bool check = true;

            for( int j =0 ; j<m ; j++){
                if((abs(val-arr2[j]))<=d){
                    check = false;
                    break;
                }  

            }
            if(check ==true){
                ans++ ;
            }
        }
        return ans;
    }
};