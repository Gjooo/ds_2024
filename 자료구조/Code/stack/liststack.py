class ListStack:
    def __init__(self):
        self.__stack = []
    def push(self, x):
        self.__stack.append(x)
        return
    def pop(self):
        return self.__stack.pop()
    def top(self):
        return self.__stack[len(self.__stack)-1]
    def isEmpty(self):
        if not self.__stack:
            return True
        else:
            return False
    def popAll(self):
        self.__stack = []