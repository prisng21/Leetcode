class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        int cnt = 1;

        while(true){
            int val = k * cnt;

            if(mp.find(val) == mp.end()){
                return val;
            }

            cnt++;
        }
    }
};