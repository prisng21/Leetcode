class Solution {
public:

     void solve(vector<int>&candidates , int target , int index , vector<int>&curr , vector<vector<int>>&result){
        if(target<0){
            return ;
        }

        if(target==0){
            result.push_back(curr);
            return ;
        }

        for(int i = index ; i<candidates.size() ; i++){
            if( i>index && candidates[i]==candidates[i-1]){   // remove duplicates
                continue;
            }

            curr.push_back(candidates[i]);  //DO or pick
            solve(candidates , target-candidates[i] , i + 1, curr , result);   // explore

            curr.pop_back();  // remove 

            // solve(candidates , target , index++, curr , result); // not pick


        }
     }




    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;

        sort(candidates.begin(),candidates.end());

        solve(candidates , target , 0,curr,result);
        return result;



        
    }
};