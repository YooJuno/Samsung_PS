class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        keys = set(nums)
        answer = 0
        
        for key in keys:
            if nums.count(key) > len(nums) / 2:
                answer = key
                break
        return answer
