class Solution(object):
    def addDigits(self, num):
        while True: 
            if num // 10 < 1: 
                return num 
            num_list = list(map(int, list(str(num)))) 
            sum_num = sum(num_list) 
            num = sum_num


        