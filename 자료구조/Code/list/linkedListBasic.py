from listNode import ListNode

class linkedListBasic:
    def __init__(self):
        '''
        더미 헤드 __head를 만듦
        항목 갯수를 0으로 초기화
        '''
        self.__head = ListNode('dummy', None)
        self.__numItems = 0

    def insert(self, i:int, newItem):
        '''
        i가 list의 item 갯수보다 적으면,
        i번째에 newItem 값을 넣어라
        그렇지 않으면 error 출력
        '''
        if i >= 0 and i <= self.__numItems:
            prev = self.__getNode(i - 1)
            newNode = ListNode(newItem, prev.next)
            prev.next = newNode
            self.__numItems += 1
        else:
            print("index", i, "out of bound in insert()")
    
    def append(self, newItem):
        '''
        newItem을 list의 맨 끝에 삽입해라.
        이전 node의 next 속성에 newNode를 부여.
        __numItems를 1 증가
        '''
        prev = self.__getNode(self.__numItems - 1)
        newNode = ListNode(newItem, prev.next)
        prev.next = newNode
        self.__numItems += 1

    def pop(self, i:int = None):
        '''
        i가 0 이상 list 길이 이하이면
        prev의 next 속성에 다음 노드(next)를 부여.
        __numItems를 1 감소
        '''
        if (i >= 0 and i <= self.__numItems - 1):
            prev = self.__getNode(i - 1)
            curr = prev.next
            prev.next = curr.next
            retItem = curr.item
            self.__numItems -= 1
            return retItem
        elif i==None:
            prev = self.__getNode(self.__numItems-1)
            retItem = prev.item
            prev.next = None
            return retItem
        else:
            return None
    
    def remove(self, x):
        '''
        x를 찾음. x가 list에 없으면 아무것도 안함
        x가 list에 있으면
        이전 node의 next 속성에 다음 노드를 부여
        __numitems를 1 감소
        '''
        (prev, curr) = self.__findNode(x)
        if curr != None:
            prev.next = curr.next
            self.__numItems -= 1
            return x
        else:
            return None
        
    def get(self, i:int):
        '''
        i번째의 item을 return하는 함수.
        list가 비었다면 None을 return.
        __getNode(i) 함수로 i번째 노드를 가져오고,
        i번째 노드의 item을 return'''
        if self.isEmpty():
            return None
        if (i >= 0 and i <= self.__numItems - 1):
            return self.__getNode(i).item
        else:
            return None
        

    def index(self, x) -> int:
        '''
        x 값의 index를 return하는 함수.
        curr 변수를 첫 번째 노드로 설정
        노드의 갯수 동안 curr의 값이 x인지 확인
        x인 curr을 찾으면 그 index를 return
        아니면 -2(없는 인덱스)를 return
        '''
        curr = self.__head.next
        for index in range(self.__numItems):
            if curr.item == x:
                return index
            else:
                curr = curr.next
        return -2

    def isEmpty(self) -> bool:
        return self.__numItems == 0

    def size(self) -> int:
        return self.__numItems

    def clear(self):
        self.__head = ListNode('dummy', None)
        self.__numItems = 0

    def count(self, x) -> int:
        cnt = 0
        curr = self.__head.next
        while curr != None:
            if curr.item == x:
                cnt += 1
                curr = curr.next
        return cnt

    def extend(self, a):
        for index in range(a.size()):
            self.append(a.get(index))


    def copy(self):
        a = linkedListBasic()
        for index in range(self.__numItems):
            a.append(self.get(index))
        return a

    def reverse(self):
        a = linkedListBasic()
        for index in range(self.__numItems):
            a.insert(0, self.get(index))
        self.clear()
        for index in range(a.size()):
            self.append(a.get(index))

    def sort(self) -> None:
        a = []
        for index in range(self.__numItems):
            a.append(self.get(index))
        a.sort()
        self.clear()
        for index in range(len(a)):
            self.append(a[index])

    def __findNode(self, x) -> (ListNode, ListNode):
        prev = self.__head
        curr = prev.next
        while curr != None:
            if curr.item == x:
                return (prev, curr)

    def __getNode(self, i:int) -> ListNode:
        curr = self.__head
        for index in range(i+1):
            curr = curr.next
        return curr

    def printList(self):
        curr = self.__head.next
        while curr != None:
            print(curr.item, end = ' ')
            curr = curr.next
        print()

    def __iter__(self):
        self.position = 0
        return self
    
    def __next__(self):
        if self.position >= self.__numItems:
            raise StopIteration
        result = self.get(self.position)
        self.position += 1
        return result