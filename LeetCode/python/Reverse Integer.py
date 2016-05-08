class Solution:
    # @return an integer
    def reverse(self, x):
        l = []
        s = str(x)[::-1]
        if s[-1] == '-':
            l.append('-')
        for i in range(0, len(s)-1):
            if s[i] == '0' and len(l) > 0 and l[-1] == '-':
                continue
            else:
                l.append(s[i])
        if s[-1] != '-':
            l.append(s[-1])
        if len(l) == 0:
            return 0
        if l[0] == '-':
            s = ''.join(l[1:])
            if len(s) >= 10 and s > '2147483647':
                return 0
            else:
                s = '-' + s
                return int(s)
        else:
            s = ''.join(l)
            if len(s) >= 10 and s > '2147483647':
                return 0
            else:
                return int(s)

# class Solution {
# public:
#     int reverse(int x) {
#         int i,s = 0;
#         for(i = 0; x != 0; i++)
#         {
#             s = (s+x % 10)*10;
#             x = x / 10; 
#         }
#         if(x < 0)
#             s = -s;
#         return s/10;
#     }

# };