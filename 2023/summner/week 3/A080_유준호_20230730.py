class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        count = {}
        half_length = len(nums) // 2

        for num in nums:
            count[num] = count.get(num, 0) + 1
            if count[num] > half_length:
                return num