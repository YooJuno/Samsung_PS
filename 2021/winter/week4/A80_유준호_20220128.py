class Solution:
    def majorityElement(self, nums):
        count = 0
        major = None
        for n in nums:
            if count == 0:
                major = n
            if n == major:
                count += 1
            else:
                count -= 1
        return major