class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
        if s == None:     
            return False
        p = re.compile('\w+')
        ns = ''.join(p.findall(s)).lower()
        if len(ns) == 0:               
            return True
        if len(ns) == 1:
            return True
        i = 0
        j = len(ns) - 1
        while i <= j:
            if ns[i] == ns[j]:
                i = i + 1
                j = j - 1
                continue
            else:
                return False
        return True