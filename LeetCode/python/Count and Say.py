class Solution:
    def __init__(self):
        self.result = None
    # @return a string
    def countAndSay(self, n):
        if n == 0:
            return ''
        elif n == 1:
            return '1'
        elif n == 2:
            return '11'
        n = n - 2
        l = ['1', '1']
        self.reS(l, n)
        return self.result
    
    def reS(self, orgl, n):
        orgin = ''.join(orgl)
        l = []
        s = []
        s.append(orgin[0])
        length = 0
        i = 0
        while i < len(orgin):
            if orgin[i] == s[-1]:
                length += 1
                if i == len(orgin) - 1:
                    l.append(str(length))
                    l.append(s[-1])
                i = i + 1
                continue
            if orgin[i] != s[-1]:
                l.append(str(length))
                l.append(s[-1])
                s.append(orgin[i])
                length = 0
                continue
        if n == 1:
            self.result = ''.join(l)
            return
        self.reS(l, n-1)