#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode {
    QDataType a;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    QueueNode* head;
    QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
void QueueInit(Queue* pq) {
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}
void QueueDestroy(Queue* pq) {
    assert(pq);
    QueueNode* cur = pq->head;
    while (cur != NULL) {
        QueueNode* next =cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}
int QueueSize(Queue* pq) {
    assert(pq);
    int n = 0;
    QueueNode* cur = pq->head;
    while (cur) {
        ++n;
        cur = cur->next;
    }
    return n;
}
bool QueueEmpty(Queue* pq) {
    assert(pq);
    return pq->head == NULL;
}
void QueuePush(Queue* pq, QDataType x) {
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->a = x;
    newnode->next = NULL;
    if (pq->head == NULL) {
        pq->head = pq->tail = newnode;
    }
    else {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}
void QueuePop(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    QueueNode* next = pq->head->next;
    free(pq->head);
    pq->head = next;
    if (pq->head == NULL) {
        pq->tail = NULL;
    }
}
QDataType QueueFront(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->a;
}

QDataType QueueBack(Queue* pq) {
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->a;
}

typedef struct {
    Queue q1;
    Queue q2;
} MyStack;

MyStack* myStackCreate() {
    MyStack* st = (MyStack*)malloc(sizeof(MyStack));
    QueueInit(&st->q1);
    QueueInit(&st->q2);
    return st;
}

void myStackPush(MyStack* obj, int x) {

    if (!QueueEmpty(&obj->q1)) {
        QueuePush(&obj->q1, x);
    }
    else {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj) {

    Queue* nullQ = &obj->q1;
    Queue* nonnullQ = &obj->q2;
    if (!QueueEmpty(&obj->q1)) {
        nullQ = &obj->q2;
        nonnullQ = &obj->q1;
    }
    while (QueueSize(nonnullQ) > 1) {
        QueuePush(nullQ, QueueFront(nonnullQ));
        QueuePop(nonnullQ);
    }
    int top = QueueFront(nonnullQ);
    QueuePop(nonnullQ);
    return top;
}

int myStackTop(MyStack* obj) {

    if (!QueueEmpty(&obj->q1)) {
        return QueueBack(&obj->q1);
    }
    else {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {

    QueueDestroy(&obj->q1);
    QueueDestroy(&obj->q2);
    free(obj);

}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main() {
    MyStack* st = myStackCreate();
    myStackPush(st, 1);
    myStackPush(st, 2);
    myStackPush(st, 3);
    myStackPush(st, 4);
    myStackPop(st);
    myStackPop(st);
    printf("top = %d\n", myStackTop(st));
    myStackFree(st);
    return 0;
}