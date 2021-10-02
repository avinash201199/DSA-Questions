#LeetCode 55

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        n = len(nums)
        goal = n - 1
        
        for i in range(n-2,-1,-1):
            
            if nums[i] + i >= goal:
                goal = i
            
        return goal == 0