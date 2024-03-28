#include "linkedlist.h"

typedef struct ListNodeStruct
{
    int item;
    ListNode_t* next;
} ListNode_t;

typedef struct LinkedListStruct
{
    ListNode_t* tail;
    int numItems;
} LinkedList_t;


ListNode_t* ListNode(int item, ListNode_t* next)
{
    ListNode_t* node = (ListNode_t*)malloc(sizeof(ListNode_t));
    if (!node) {
        printf("Failed to alloc\n");
        return NULL;
    }
    node->item = item;
    node->next = next;

    return node;
}

void destroyListNode(ListNode_t* node)
{
    free(node);
    return;
}

LinkedList_t* LinkedList()
{
    LinkedList_t* tmp = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    tmp->tail = ListNode(-1, NULL);
    tmp->numItems = 0;

    return tmp;
}


void destroyLinkedList(LinkedList_t* list)
{
    clearLinkedList(list);
    destroyListNode(list->tail);
    free(list);
}

void insertLinkedList(LinkedList_t* list, int i, int newItem)
{
    if (i == list->numItems)
    {
        appendLinkedList(list, newItem);
        return;
    }
    else if (i == 0)
    {
        ListNode_t* prev = list->tail->next;
        ListNode_t* curr = prev->next;
        ListNode_t* newNode = ListNode(newItem, NULL);
        prev->next = newNode;
        newNode->next = curr;
        (list->numItems)++;
    }
    else if (i > 0 && i < list->numItems)
    {
        ListNode_t* prev = getNodeLinkedList(list, i - 1);
        ListNode_t* curr = prev->next;
        ListNode_t* newNode = ListNode(newItem, NULL);
        prev->next = newNode;
        newNode->next = curr;
        (list->numItems)++;
    }
    else
    {
        return;
    }
}

void appendLinkedList(LinkedList_t* list, int newItem)
{
    ListNode_t* newNode = ListNode(newItem, NULL);
    if (list->numItems == 0)
    {
        newNode->next = newNode;
        list->tail->next = newNode;
        (list->numItems)++;
        return;
    }
    else
    {
        ListNode_t* prev = list->tail->next;
        ListNode_t* curr = prev->next;
        prev->next = newNode;
        newNode->next = curr;
        list->tail->next = newNode;
        (list->numItems)++;
        return;
    }
}

int popLinkedList(LinkedList_t* list, int index)
{
    if (index == -1)
        index = list->numItems - 1;
    if (list->numItems == 0)
    {
        return -2;
    }

    if (list->numItems == 1 && index == 0)
    {
        ListNode_t* temp = list->tail->next;
        int rtnItem = temp->item;
        list->tail->next = NULL;
        (list->numItems)--;
        destroyListNode(temp);
        return rtnItem;
    }

    if (index == 0)
    {
        ListNode_t* prev = list->tail->next;
        ListNode_t* curr = prev->next;
        int rtnItem = curr->item;
        prev->next = curr->next;
        (list->numItems)--;
        destroyListNode(curr);
        return rtnItem;
    }

    if (index >= 1 && index <= list->numItems - 1)
    {
        ListNode_t* prev = getNodeLinkedList(list, index - 1);
        ListNode_t* curr = prev->next;
        int rtnItem = curr->item;
        prev->next = curr->next;
        (list->numItems)--;
        if (index == list->numItems - 1)
            list->tail->next = prev;
        destroyListNode(curr);
        return rtnItem;
    }

    return -2;
}

int removeLinkedList(LinkedList_t* list, int x)
{
    if (list->numItems == 0) return -1;
    if (list->numItems == 1)
    {
        if (list->tail->next->item == x)
        {
            ListNode_t* temp = list->tail->next;
            (list->numItems)--;
            list->tail->next = NULL;
            destroyListNode(temp);
            return x;
        }
        else
        {
            return -1;
        }
    }
    ListNode_t* prev = findPrevNodeLinkedList(list, x);
    if (prev == NULL)
    {
        return -1;
    }
    ListNode_t* curr = prev->next;
    prev->next = curr->next;
    (list->numItems)--;
    destroyListNode(curr);
    return x;
}

int getLinkedList(LinkedList_t* list, int i)
{
    if (list->numItems == 0)
    {
        return -1;
    }
    else if (i >= 0 && i < list->numItems) {
        ListNode_t* temp = getNodeLinkedList(list, i);
        return (temp->item);
    }
    else {
        return -1;
    }
}

int indexLinkedList(LinkedList_t* list, int x)
{
    if (list->numItems == 0) return -2;
    ListNode_t* curr = list->tail->next;
    for (int i = 0; i < list->numItems - 1; i++)
    {
        curr = curr->next;
        if (curr->item == x) {
            return i;
        }
    }
    return -2;
}

void clearLinkedList(LinkedList_t* list)
{
    if (list->numItems == 0) { return; }
    ListNode_t* temp;
    int i = list->numItems;
    while (i--)
    {
        temp = getNodeLinkedList(list, i);
        destroyListNode(temp);
    }
    list->tail->next = NULL;
    list->numItems = 0;
    // while (list->tail->next != NULL)
    // {
    //     index++;
    //     for (int i = 0; i < index; i++)
    //     {

    //         curr = curr->tail->next;
    //         if (curr->next == NULL)
    //         {
    //             free(curr);
    //             index = 0;
    //         }
    //     }
    // }
}

int countLinkedList(LinkedList_t* list, int x)
{
    int cnt = 0;
    ListNode_t* curr = list->tail->next->next;

    while (curr->next != list->tail->next)
    {
        if (curr->item == x)
        {
            cnt++;
        }

        curr = curr->next;
    }
    return cnt;
}

void extendLinkedList(LinkedList_t* list, LinkedList_t* a)
{
    if (a->numItems == 0) { return; }

    ListNode_t* prev = getNodeLinkedList(list, list->numItems - 1);
    ListNode_t* curr = a->tail->next;
    LinkedList_t* Copy = LinkedList();
    for (int i = 0; i < a->numItems; i++)
    {
        appendLinkedList(Copy, getLinkedList(a, i));
    }
}

LinkedList_t* copyLinkedList(LinkedList_t* list)
{
    LinkedList_t* a = LinkedList();
    ListNode_t* temp = list->tail->next->next;
    for (int i = 0; i < list->numItems; i++)
    {
        appendLinkedList(a, temp->item);
        temp = temp->next;
    }
    return a;
}

ListNode_t* findPrevNodeLinkedList(LinkedList_t* list, int x)
{
    if (list->numItems == 0) return NULL;
    ListNode_t* prev = list->tail->next;
    ListNode_t* curr = prev->next;
    while (curr != list->tail->next)
    {
        if (curr->item == x)
        {
            return prev;
        }
        prev = prev->next;
        curr = curr->next;
    }

    return NULL;
}

ListNode_t* getNodeLinkedList(LinkedList_t* list, int order)
{
    if (list->numItems == 0) return NULL;
    if (order == list->numItems - 1 || order == -1) return list->tail->next;
    if (order >= list->numItems) {
        return NULL;
    }
    ListNode_t* curr = (list->tail->next->next);

    for (int i = 0; i < order; i++)
    {
        curr = curr->next;
    }
    return curr;
}


void printLinkedList(LinkedList_t* list)
{
    ListNode_t* curr = list->tail->next;
    for (int i = 0; i < list->numItems; i++)
    {
        curr = curr->next;
        printf("%d ", curr->item);
    }
    printf("\n");
}
