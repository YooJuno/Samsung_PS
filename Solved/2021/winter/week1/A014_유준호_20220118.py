class Solution(object):
    def summaryRanges(self, nums):
        length = len(nums)
        if length == 0:
            return []
        nums.append(float('inf'))
        res, start = [], 0
        for i in range(length):
            if nums[i + 1] != nums[i] + 1:
                res.append(str(nums[i]) if i == start else "%s->%s" % (nums[start], nums[i]))
                start = i + 1
        return res
        