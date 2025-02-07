class Solution(object):
    def isPalindrome(self, s):
      s = s.lower()
      s = s.sub('[^a-z0-9]', '', s)

      return s == s[::-1]