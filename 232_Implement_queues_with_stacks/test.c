typedef int SDataType;
typedef struct Stack {
    SDataType* a;
    int top;
    int capacity;
}ST;
void StackInit(ST* st);
void StackDestory(ST* st);
void StackPush(ST* st, SDataType x);
bool StackEmpty(ST* st);
void StackPop(ST* st);
SDataType StackTop(ST* st);
int StackSize(ST* st);

void StackInit(ST* st) {
    assert(st);
    st->a = NULL;
    st->top = st->capacity = 0;
}
void StackDestory(ST* st) {
    assert(st);
    free(st->a);
    st->a = NULL;
    st->top = st->capacity = 0;
}
void StackPush(ST* st, SDataType x) {
    assert(st);
    if (st->top == st->capacity) {
        int newCapacity = st->capacity == 0 ? 4 : st->capacity * 2;
        SDataType* tmp = (SDataType*)realloc(st->a, sizeof(SDataType) * newCapacity);
        if (tmp == NULL) {
            printf("realloc fail\n");
            exit(-1);
        }
        else {
            st->a = tmp;
            st->capacity = newCapacity;
        }
    }
    st->a[st->top] = x;
    st->top++;
}
void StackPop(ST* st) {
    assert(st);
    assert(!StackEmpty(st));
    st->top--;
}
bool StackEmpty(ST* st) {
    assert(st);
    return st->top == 0;
}
SDataType StackTop(ST* st) {
    assert(st);
    assert(!StackEmpty(st));
    return st->a[st->top - 1];
}
int StackSize(ST* st) {
    assert(st);
    return st->top;
}

typedef struct {
    ST pushSt;
    ST popSt;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->pushSt);
    StackInit(&q->popSt);
    return q;
}

void myQueuePush(MyQueue* obj, int x) {

    StackPush(&obj->pushSt, x);
}

int myQueuePop(MyQueue* obj) {

    if (StackEmpty(&obj->popSt)) {
        while (!StackEmpty(&obj->pushSt)) {
            StackPush(&obj->popSt, StackTop(&obj->pushSt));
            StackPop(&obj->pushSt);
        }
    }
    int ret = StackTop(&obj->popSt);
    StackPop(&obj->popSt);
    return ret;
}

int myQueuePeek(MyQueue* obj) {
    if (StackEmpty(&obj->popSt)) {
        while (!StackEmpty(&obj->pushSt)) {
            StackPush(&obj->popSt, StackTop(&obj->pushSt));
            StackPop(&obj->pushSt);
        }
    }
    return StackTop(&obj->popSt);
}

bool myQueueEmpty(MyQueue* obj) {
    return StackEmpty(&obj->pushSt) && StackEmpty(&obj->popSt);
}

void myQueueFree(MyQueue* obj) {
    StackDestory(&obj->pushSt);
    StackDestory(&obj->popSt);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/