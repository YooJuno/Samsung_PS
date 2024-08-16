class Solution(object):
    def plusOne(self, digits):
        Length = len(digits)-1
        while Length>=0:
            if Length==0:
                if digits[Length]+1>9:
                    digits[Length] = 0
                    result=[1]
                    result.extend(digits)
                    return result
            if digits[Length]+1<=9:
                digits[Length] +=1
                return digits
            else:
                digits[Length]=0
                Length -= 1
        return digits