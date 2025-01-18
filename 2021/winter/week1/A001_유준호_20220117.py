class Solution(object):
    def findContentChildren(self, g, s):
        g.sort(reverse=True)
        s.sort(reverse=True)

        content = 0
        index = 0
        for cookie in range(0, len(s)):
            for greed in range(index, len(g)):
                if s[cookie] >= g[greed]:
                    content += 1
                    index = greed + 1
                    break

        return content