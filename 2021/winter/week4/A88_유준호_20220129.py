class MinStack:

    def __init__(self):
        self.__stack=[]

    def push(self, x: int) -> None:
        if self.__stack:
            self.__stack.append((x,min(x,self.__stack[-1][1])))  # (x,minimum)
        else:
            self.__stack.append((x,x))
        
                      
    def pop(self) -> None:
        if self.__stack:
            self.__stack.pop()
        
    def top(self) -> int:
        if self.__stack:
            return self.__stack[-1][0]
        

    def getMin(self) -> int:
        return self.__stack[-1][1]