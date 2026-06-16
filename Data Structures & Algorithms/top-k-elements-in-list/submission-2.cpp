class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> hash (nums.size() + 1);
        int cnt = 1;
        if (nums.size() == 1) hash[1].push_back(nums[0]);
        for(int i=0;i< (int)nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                cnt++;
                if(i+1 == nums.size()-1){
                    hash[cnt].push_back(nums[i]);
                    cnt = 1;
                }
            }
            else{
                hash[cnt].push_back(nums[i]);
                cnt = 1;
                if(i+1 == nums.size()-1) hash[1].push_back(nums[i+1]);
            }
        }
        
        vector<int> ans;
        int foundCnt =0;

        for(int i= hash.size()-1;i>=0;i--){
            for(int val : hash[i]){
                if(foundCnt == k){
                    break;
                }
                ans.push_back(val);
                foundCnt++;
            }
            if(foundCnt == k) break;
        }
        return ans;
        
    }
};