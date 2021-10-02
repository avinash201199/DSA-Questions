#LeetCode 45

class Solution:
    def jump(self, nums: List[int]) -> int:
        
        n = len(nums)
        max_reach = curr_reach = res = 0
        
        for i in range(n-1):
            
            max_reach = max(max_reach, nums[i] + i)
            
            if i == curr_reach:
                res += 1
                curr_reach = max_reach
        
        return res