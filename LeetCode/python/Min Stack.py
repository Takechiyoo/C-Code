class MinStack:
    # @param x, an integer
    # @return an integer
    def __init__(self):
        self.L = []
        self.m = []
        self.length = 0
        # self.mv = None
        
    
    def push(self, x):
        self.L.append(x)
        if self.length == 0:
            l = [x, self.length]
            self.m.append(l)
            self.length += 1
            self.mv = x
        else:
            if x < self.mv:
                l = [x, self.length]
                self.m.append(l)
                self.length += 1
                self.mv = x
            else:
                self.length += 1

    # @return nothing
    def pop(self):
        y = [self.L[-1], self.length-1]
        if y in self.m:
            self.m.pop()
            if len(self.m) != 0: 
                l = self.m[-1]
                self.mv = l[0]
            
        self.length -= 1
        self.L.pop()
                

    # @return an integer
    def top(self):
        return self.L[-1]

    # @return an integer
    def getMin(self):
        return self.mv
        