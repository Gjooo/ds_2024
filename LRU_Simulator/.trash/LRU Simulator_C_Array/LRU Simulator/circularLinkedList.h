#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeStruct ListNode_t;
typedef struct LinkedListStruct LinkedList_t;

typedef struct ListNodeStruct
{
    int item;
    ListNode_t* next;
} ListNode_t;

typedef struct LinkedListStruct
{
    ListNode_t* head;
    int numItems;
} LinkedList_t;

ListNode_t* ListNode(int item, LinkedList_t* next); // ListNode 积己 窃荐
LinkedList_t* LinkedList(); //LinkedList 积己 窃荐
void destroyListNode(ListNode_t* node);
void destroyLinkedList(LinkedList_t* list);
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
ListNode_t* findPrevNodeLinkedList(LinkedList_t* list, int x);
ListNode_t* getNodeLinkedList(LinkedList_t* list, int order);