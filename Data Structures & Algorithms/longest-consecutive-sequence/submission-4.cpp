
class Solution {
private:
    int max(int a, int b){
        return a>b?a:b;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }
        int cnt=0;
        int maxcnt=1;
        for(auto ele : mp){
            cnt =1;
            if(!mp.count(ele.first-1)){
                int current = ele.first;
                while(mp.count(current+1)){
                    cnt++;
                    current++;
                }
            }
            maxcnt = max(maxcnt,cnt);
        }
        return maxcnt;

   }

};
