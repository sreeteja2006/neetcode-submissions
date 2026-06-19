class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_res = INT_MIN;
        
        int prefix = 1;
        int suffix = 1;
        
        for (int i = 0; i < n; i++) {
            // If we hit a 0, reset the product to 1
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            
            prefix = prefix * nums[i];
           
            suffix = suffix * nums[n - 1 - i];
            

            max_res = max({max_res, prefix, suffix});
        }
        
        return max_res;
    }
};