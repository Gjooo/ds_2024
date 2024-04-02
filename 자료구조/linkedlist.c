#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeStruct ListNode_t;
typedef struct LinkedListStruct LinkedList_t;

void initLinkedList(LinkedList_t* list);
void insertLinkedList(LinkedList_t* list, int i, int newItem);
void appendLinkedList(LinkedList_t* list, int newItem);
int popLinkedList(LinkedList_t* list, int i);
int removeLinkedList(LinkedList_t* list, int x);
int getLinkedList(LinkedList_t* list, int i);
int indexLinkedList(LinkedList_t* list, int x);
void clearLinkedList(LinkedList_t* list);
int countLinkedList(LinkedList_t* list, int x);
void extendLinkedList(LinkedList_t* list, LinkedList_t* a);
void printLinkedList(LinkedList_t* list);
ListNode_t* findPrevNodeLinkedList(LinkedList_t *list, int x);
ListNode_t* getNodeLinkedList(LinkedList_t *list, int order);
void destroyLinkedList(LinkedList_t *list);



typedef struct ListNodeStruct
{
    int item;
    ListNode_t *next;
} ListNode_t;

typedef struct LinkedListStruct
{
    ListNode_t *head;
    int numItems;
} LinkedList_t;

ListNode_t *ListNode(int item, ListNode_t *next)
{
    ListNode_t *this = malloc(sizeof(ListNode_t));
    this->item = item;
    this->next = next;

    return this;
}

LinkedList_t *LinkedList(ListNode_t *head, int numItems)
{
    LinkedList_t *this = malloc(sizeof(LinkedList_t));
    this->head = head;
    this->numItems = numItems;

    return this;
}

void initLinkedList(LinkedList_t *list)
{
    list->head->item = -1;
    list->head->next = NULL;
}


void insertLinkedList(LinkedList_t *list, int i, int newItem)
{
    if(i >= 0 && i < list->numItems)
    {
        ListNode_t* prev = getNodeLinkedList(list, i - 1);
        ListNode_t* newNode;
        newNode->item = newItem;
        newNode->next = prev->next;
        prev->next = newNode;
        list->numItems++;
        return;
    } else if(i==list->numItems) {
        appendLinkedList(list, newItem);
        return;
    } else {
        printf("index %d out of bound in insert.", i);
        return;
    }
}

void appendLinkedList(LinkedList_t *list, int newItem)
{
    ListNode_t* temp;
    temp->item = newItem;
    temp->next = NULL;
    if(list->numItems==0)
    {
        list->head->next = temp;
    } else {
        ListNode_t* curr = getNodeLinkedList(list, newItem-1);
        curr->next = temp;
    }
    list->numItems++;
    return;
}

int popLinkedList(LinkedList_t *list, int i)
{
    if(i==NULL)
    {
        ListNode_t* prev = getNodeLinkedList(list, list->numItems-2);
        int ret = prev->next->item;
        free(prev->next);
        prev->next = NULL;
        list->numItems--;
        return ret;
    } else if(i >= 0 && i <= (list->numItems)-1)
    {
        ListNode_t* prev = getNodeLinkedList(list, list->numItems-2);
        ListNode_t* curr = prev->next;
        int ret = curr->item;
        prev->next = curr->next;
        free(curr);
        list->numItems--;
        return ret;
    } else {
        return NULL;
    }
}

int removeLinkedList(LinkedList_t* list, int x)
{
    ListNode_t* prev = findPrevNodeLinkedList(list, x);
    ListNode_t* curr = prev->next;
    if(prev == NULL)
    {
        return NULL;
    } else {
        prev->next = curr->next;
        list->numItems--;
        free(curr);
        return x; 
    }
}

int getLinkedList(LinkedList_t* list, int i)
{
    if (list->numItems==0)
    {
        return NULL;
    } else if( i >= 0 && i <= list->numItems -1) {
        ListNode_t* temp = getNodeLinkedList(list, i);
        return (temp -> item);
    } else {
        return NULL;
    }
}

int indexLinkedList(LinkedList_t* list, int x)
{
    ListNode_t* curr = list->head->next;
    for(int i=0;i<list->numItems;i++) {
        if(curr->item==x) {
            return i;
        } else {
            curr = curr->next;
        }
    }
    return -2;
}

void clearLinkedList(LinkedList_t* list)
{
    ListNode_t* temp;
    for(int i=list->numItems-1;i==-1;i--)
    {
        temp = getNodeLinkedList(list, i);
        free(temp);
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
    ListNode_t* curr = list->head->next;
    while(curr!=NULL)
    {
        if(curr->item == x)
        {
            cnt++;
            curr = curr->next;
        }
    }
    return cnt;
}

void extendLinkedList(LinkedList_t* list, LinkedList_t* a)
{
    ListNode_t* prev = getNodeLinkedList(list, list->numItems-1);
    for(int i=0;i<a->numItems-1;i++) {

    }
}

void printLinkedList(LinkedList_t* list)
{
    ListNode_t* curr = list->head;
    for(int i=0;i<list->numItems;i++)
    {
        curr = curr->next;
        printf("%d ", curr->item);
    }
    printf("\n");
}

ListNode_t* findPrevNodeLinkedList(LinkedList_t *list, int x)
{
    ListNode_t* prev = list->head;
    ListNode_t* curr = prev->next;
    while (curr->next != NULL)
    {
        if(curr->item == x)
        {
            return prev;
        }
        curr = prev->next;
    }

    return;
}

ListNode_t* getNodeLinkedList(LinkedList_t *list, int order)
{
    ListNode_t *curr = (list->head->next);

    for (int i = 0; i < order; i++)
    {
        curr = curr->next;
    }
    return curr;
}

void destroyLinkedList(LinkedList_t *list)
{
    clearLinkedList(list);
    free(list->head);
    free(list);
}

int main(void)
{
    LinkedList_t *exam;
    appendLinkedList(exam, 1);
    insertLinkedList(exam, 0, 2);
    printLinkedList(exam);
    destroyLinkedList(exam);
    // init(exam);
}