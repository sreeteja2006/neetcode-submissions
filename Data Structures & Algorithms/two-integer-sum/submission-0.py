class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer = []
        for i in range(len(nums)):
            for j in range(len(nums)):
                if(nums[i]+nums[j]==target and i!=j):
                    answer.append(i)
                    answer.append(j)
        answer = set(answer)
        answer = list(answer)
        return answer

        