class Solution(object):
    def calPoints(self, ops):
        tmp=[]
        for i in ops:
            if i=='C': tmp.pop()
            elif i=='D':tmp.append (tmp[-1]*2)
            elif i=="+":tmp.append(tmp[-1]+tmp[-2])
            else : tmp.append(int(i))
        return (sum(tmp))