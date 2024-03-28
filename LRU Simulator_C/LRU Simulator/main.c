#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

//10만개 입력 받기






int main(void)
{
    LinkedList_t* exam = LinkedList();
    appendLinkedList(exam, 1);
    insertLinkedList(exam, 0, 2);
    insertLinkedList(exam, 2, 3);
    LinkedList_t* exam2 = LinkedList();
    appendLinkedList(exam2, 10);
    appendLinkedList(exam2, 20);
    appendLinkedList(exam2, 30);
    extendLinkedList(exam, exam2);
    printLinkedList(exam);
    destroyLinkedList(exam);
    destroyLinkedList(exam2);
    // init(exam);
}