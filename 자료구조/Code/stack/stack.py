class itemNode:
    def __init__(self, prev:'itemNode', item) -> None:
        self.prev = prev
        self.item = item

class LinkedStack:
    def __init__(self) -> None:
        self.__tail = itemNode(None, 'dummy')
        
    def push(self, x):
        if self.__tail.prev == None:
            self.__tail.prev = itemNode(None, x)
        else:
            curr = self.__tail.prev
            self.__tail.prev = itemNode(curr, x)
      
    def pop(self, x):
        if self.__tail.prev == None:
            return None
        else:
            pp = self.__tail.prev
            curr = self.__tail.prev.prev
            self.__tail.prev = curr
            return pp
    
    def top(self):
        return self.__tail.prev.item
    
    def isEmpty(self):
        if self.__tail.prev == None:
            return True
        else:
            return False
    
    def popAll(self):
        self.__tail = itemNode(None, 'dummy')
        
    def printStack(self):
        curr = self.__tail.prev
        while curr != None:
            print(curr.item, end=' ')
            curr = curr.prev