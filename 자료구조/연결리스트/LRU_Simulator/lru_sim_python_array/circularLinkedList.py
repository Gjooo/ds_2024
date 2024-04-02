from listNode import ListNode

#기본 개념
#list에 뭘 넣는다: prev랑 curr 노드를 찾는다 -> newItem노드를 만들고 prev.next와 newItem.next값을 정리한다. ->(필요한 경우) -> __tail.next를 고친다. -> __itemNum++
#list에 뭘 뺀다: prev랑 curr 노드를 찾는다 -> prev.next=curr.next -> (필요한 경우) __tail을 고친다. -> __listNum--


# LRU 시뮬레이터에 필요한 매서드
# insert, index, 

class circularLinkedListBasic:
    def __init__(self):
        '''
        더미 헤드 __head를 만듦
        항목 갯수를 0으로 초기화
        '''
        self.__tail = ListNode('dummy', None)
        self.__numItems = 0

    def insert(self, i:int, newItem):
        '''
        i가 list의 item 갯수보다 적으면,
        i번째에 newItem 값을 넣어라
        그렇지 않으면 error 출력
        '''
        if i == self.__numItems:
            self.append(newItem)
            return
        elif i==0:
            prev = self.__tail.next
            curr = prev.next
            newNode = ListNode(newItem, None)
            prev.next = newNode
            newNode.next = curr
            self.__numItems += 1
        elif (i > 0 and i < self.__numItems):
            prev = self.__getNode(i-1)
            curr = prev.next
            newNode = ListNode(newItem, None)
            prev.next = newNode
            newNode.next = curr
            self.__numItems += 1
        else:
            return
    
    def append(self, newItem):
        '''
        newItem을 list의 맨 끝에 삽입해라.
        이전 node의 next 속성에 newNode를 부여.
        __numItems를 1 증가
        '''
        newNode = ListNode(newItem, None)
        if self.isEmpty():
            newNode.next = newNode
            self.__tail.next = newNode
            self.__numItems += 1
            return
        else:
            prev = self.__tail.next
            curr = prev.next
            prev.next = newNode
            newNode.next = curr
            self.__tail.next = newNode
            self.__numItems += 1

    def pop(self, *args):
        '''
        i가 0 이상 list 길이 이하이면
        prev의 next 속성에 다음 노드(next)를 부여.
        __numItems를 1 감소
        '''
        if self.isEmpty():
            return None
        if len(args) != 0:
            i = args[0]
        if len(args) == 0 or i == -1:
            i = self.__numItems - 1
        
        if self.size() == 1 and i == 0:
            rtnItem = self.__tail.next.item
            self.__tail.next = None
            self.__numItems -= 1
            return rtnItem
        
        if i==0:
            prev = self.__tail.next
            curr = prev.next
            rtnItem = curr.item
            prev.next = curr.next
            self.__numItems -=1
            return rtnItem
        
        if (i >= 1 and i<= self.__numItems - 1):
            prev = self.__getNode(i-1)
            curr = prev.next
            rtnItem = curr.item
            prev.next = curr.next
            self.__numItems -= 1
            if (i == self.__numItems - 1):
                self.__tail.next = prev
                
            return rtnItem
            
            
    def remove(self, x):
        '''
        x를 찾음. x가 list에 없으면 아무것도 안함
        x가 list에 있으면
        이전 node의 next 속성에 다음 노드를 부여
        __numitems를 1 감소
        '''
        if self.isEmpty(): return None
        if self.size() == 1:
            if self.__tail.next.item==x:
                self.__numItems -= 1
                self.__tail.next = None
                return x
            else:
                return None
        (prev, curr) = self.__findNode(x)
        if prev==None:
            return None
        prev.next = curr.next
        self.__numItems -= 1
        return x
        
        
    def get(self, i:int):
        '''
        i번째의 item을 return하는 함수.
        list가 비었다면 None을 return.
        __getNode(i) 함수로 i번째 노드를 가져오고,
        i번째 노드의 item을 return'''
        if self.isEmpty(): return None
        return self.__getNode(i).item
        

    def index(self, x) -> int:
        '''
        x 값의 index를 return하는 함수.
        curr 변수를 첫 번째 노드로 설정
        노드의 갯수 동안 curr의 값이 x인지 확인
        x인 curr을 찾으면 그 index를 return
        아니면 -2(없는 인덱스)를 return
        '''
        if self.isEmpty(): return -2
        curr = self.__tail.next
        for i in range(self.__numItems):
            curr = curr.next
            if curr.item==x:
                return i
        return -2

    def isEmpty(self) -> bool:
        return self.__numItems == 0

    def size(self) -> int:
        return self.__numItems

    def clear(self):
        self.__tail = ListNode('dummy', None)
        self.__numItems = 0

    def count(self, x) -> int:
        cnt = 0
        curr = self.__tail.next.next
        while curr.next != self.__tail.next:
            if curr.item == x:
                cnt += 1
            curr = curr.next
        return cnt

    def extend(self, a):
        for index in range(a.size()):
            self.append(a.get(index))


    def copy(self):
        a = circularLinkedListBasic()
        temp = self.__tail.next.next
        for index in range(self.__numItems):
            a.append(temp.item)
            temp = temp.next
        return a

    def reverse(self):
        a = circularLinkedListBasic()
        for index in range(self.__numItems):
            a.insert(0, self.get(index))
        self.clear()
        temp = a.__tail.next.next
        for index in range(a.__numItems - 1):
            self.append(temp.item)
            temp = temp.next

    def sort(self) -> None:
        a = [None] * self.__numItems
        temp = self.__tail.next.next
        for index in range(self.__numItems):
            a[i] = temp.item
            temp = temp.next
        a.sort()
        self.clear()
        for index in range(len(a)):
            self.append(a[index])
        return
    
    def __findNode(self, x) -> (ListNode, ListNode):
        if self.isEmpty(): return (None, None)
        prev = self.__tail.next
        curr = prev.next
        while curr != self.__tail.next:
            if curr.item == x:
                return (prev, curr)
            else:
                curr = curr.next
                prev = prev.next
        return (None, None)

    def __getNode(self, i:int) -> ListNode:
        if self.isEmpty(): return None
        if (i == self.__numItems - 1 or i == -1):
            return self.__tail.next
        curr = self.__tail.next.next
        for index in range(i):
            curr = curr.next
        return curr

    def printList(self):
        if self.isEmpty(): return
        curr = self.__tail.next.next
        while curr != self.__tail.next:
            print(curr.item, end = ' ')
            curr = curr.next
        print(curr.item, end = ' ')
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