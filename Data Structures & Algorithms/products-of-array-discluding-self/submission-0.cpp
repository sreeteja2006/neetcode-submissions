
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>forwardprefixprod(nums.size(),1);
        vector<int>backprefixprod(nums.size(),1);
        int n=nums.size();
        vector<int> ans;
        for(int i=1;i<n;i++)
        {
            forwardprefixprod[i]=forwardprefixprod[i-1]*nums[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            backprefixprod[i]=backprefixprod[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(forwardprefixprod[i]*backprefixprod[i]);
        }
        return ans;
    }
};
