class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        a = len(nums)
        nums  = set(nums)
        b = len(nums)
        # print(a,b)
        if a==b:
            return False
        else:
            return True
            


         