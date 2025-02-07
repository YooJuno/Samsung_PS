class Solution:
    def singleNumber(self, nums: List[int]) -> int:
      ans = nums[0]
      for i in range(1,len(nums)):
         ans ^=nums[i]
      return ans
ob1 = Solution()
print(ob1.singleNumber([1,1,5,3,2,5,2]))