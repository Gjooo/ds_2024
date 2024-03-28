#include "linkedlist.h"

ListNode_t* ListNode(int item, ListNode_t* next)
{
    ListNode_t* node = (ListNode_t*) malloc(sizeof(ListNode_t));
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
    tmp->head = ListNode(-1, NULL);
    tmp->head->item = -1;
    tmp->head->next = NULL;
    tmp->numItems = 0;

    return tmp;
}


void destroyLinkedList(LinkedList_t* list)
{
    clearLinkedList(list);
    destroyListNode(list->head);
    free(list);
}

void insertLinkedList(LinkedList_t* list, int i, int newItem)
{
    if (i > 0 && i < list->numItems)
    {
        ListNode_t* prev = getNodeLinkedList(list, i - 1);
        ListNode_t* newNode = ListNode(newItem, prev->next);
        prev->next = newNode;
        (list->numItems)++;
        return;
    }
    else if (i == 0) {
        ListNode_t* newNode = ListNode(newItem, list->head->next);
        list->head->next = newNode;
        (list->numItems)++;
    }
    else if (i == list->numItems) {
        appendLinkedList(list, newItem);
        return;
    }
    else {
        printf("index %d out of bound in insert.", i);
        return;
    }
}

void appendLinkedList(LinkedList_t* list, int newItem)
{
    ListNode_t* newNode = ListNode(newItem, NULL);
    if (list->numItems == 0)
    {
        list->head->next = newNode;
    }
    else {
        ListNode_t* curr = getNodeLinkedList(list, list->numItems - 1);
        curr->next = newNode;
    }
    (list->numItems)++;
    return;
}

int popLinkedList(LinkedList_t* list, int i)
{
    if (i == -1)
    {
        ListNode_t* prev = getNodeLinkedList(list, list->numItems - 2);
        int ret = prev->next->item;
        destroyListNode(prev->next);
        prev->next = NULL;
        list->numItems--;
        return ret;
    }
    else if (i >= 0 && i <= (list->numItems) - 1)
    {
        ListNode_t* prev = getNodeLinkedList(list, i - 2);
        ListNode_t* curr = prev->next;
        int ret = curr->item;
        prev->next = curr->next;
        destroyListNode(curr);
        (list->numItems)--;
        return ret;
    }
    else {
        return -1;
    }
}

int removeLinkedList(LinkedList_t* list, int x)
{
    ListNode_t* prev = findPrevNodeLinkedList(list, x);
    if (prev == NULL)
    {
        return -1;
    }
    else {
        ListNode_t* curr = prev->next;
        prev->next = curr->next;
        (list->numItems)--;
        destroyListNode(curr);
        return x;
    }
}

int getLinkedList(LinkedList_t* list, int i)
{
    if (list->numItems == 0)
    {
        return -1;
    }
    else if (i >= 0 && i <= list->numItems - 1) {
        ListNode_t* temp = getNodeLinkedList(list, i);
        return (temp->item);
    }
    else {
        return -1;
    }
}

int indexLinkedList(LinkedList_t* list, int x)
{
    ListNode_t* curr = list->head->next;
    for (int i = 0; i < list->numItems-1; i++) {
        if (curr->item == x) {
            return i;
        }
        else {
            curr = curr->next;
        }
    }
    return -2;
}

void clearLinkedList(LinkedList_t* list)
{
    if (list->numItems == 0) { return; }
    ListNode_t* temp;
    for (int i = list->numItems - 1; i == -1; i--)
    {
        temp = getNodeLinkedList(list, i);
        destroyListNode(temp);
    }
    list->head->next = NULL;
    list->numItems = 0;
    // while (list->head->next != NULL)
    // {
    //     index++;
    //     for (int i = 0; i < index; i++)
    //     {

    //         curr = curr->head->next;
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
    ListNode_t* curr = list->head;

    while (curr != NULL)
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
    ListNode_t* curr = a->head->next;
    ListNode_t* currCopy;

    while(curr != NULL) {
        currCopy = ListNode(curr->item, NULL);
        prev->next = currCopy;
        ++(list->numItems);
        curr = curr->next;
        prev = prev->next;
    }
}

void copyLinkedList(LinkedList_t* list)
{
    LinkedList_t* a = LinkedList();
    for (int i = 0; i < list->numItems; i++)
    {
        appendLinkedList(a, getLinkedList(list, i));
    }
    return a;
}

void reverse(LinkedList_t* list)
{
    LinkedList_t* a = LinkedList();
    for (int i = 0; i < list->numItems; i++)
    {
        insertLinkedList(a, 0, getLinkedList(list, i));
    }
    clearLinkedList(list);
    for (int i = 0; i < a->numItems; i++)
    {
        appendLinkedList(list, getLinkedList(a, i));
    }
}

void printLinkedList(LinkedList_t* list)
{
    ListNode_t* curr = list->head;
    for (int i = 0; i < list->numItems; i++)
    {
        curr = curr->next;
        printf("%d ", curr->item);
    }
    printf("\n");
}

ListNode_t* findPrevNodeLinkedList(LinkedList_t* list, int x)
{
    ListNode_t* prev = list->head;
    ListNode_t* curr = prev->next;
    while (curr->next != NULL)
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
    if (order >= list->numItems) {
        return NULL;
    }
    ListNode_t* curr = (list->head);

    for (int i = 0; i < order + 1; i++)
    {
        curr = curr->next;
    }
    return curr;
}
