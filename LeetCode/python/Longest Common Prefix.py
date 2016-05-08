class Solution:
    # @return a string
    def longestCommonPrefix(self, strs):
        if strs == None or len(strs) == 0:
            return ''
        
        for i in range(0, len(strs[0])):
            ch = strs[0][i]
            for j in range(1, len(strs)):
                if i == len(strs[j]) or strs[j][i] != ch:
                    return strs[0][0:i]
        return strs[0]