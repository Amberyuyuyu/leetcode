 typedef struct CQNode {
     int data;
     struct CQNode* next;
 }CQNode;

 typedef struct {
     CQNode* front;
     CQNode* tail;
     int size;
     int k;
 } MyCircularQueue;
 bool myCircularQueueIsFull(MyCircularQueue* obj);
 bool myCircularQueueIsEmpty(MyCircularQueue* obj);
 MyCircularQueue* myCircularQueueCreate(int k) {
     MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
     cq->front = NULL;
     cq->tail = NULL;
     cq->size = 0;
     cq->k = k;
     return cq;
 }
 bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
     if (myCircularQueueIsFull(obj)) {
         return false;
     }
     CQNode* newnode = (CQNode*)malloc(sizeof(CQNode));
     newnode->data = value;
     newnode->next = NULL;
     if (obj->front == NULL) {
         obj->front = obj->tail = newnode;
     }
     else {
         obj->tail->next = newnode;
         obj->tail = newnode;
     }
     obj->size++;
     return true;
 }
 bool myCircularQueueDeQueue(MyCircularQueue* obj) {
     if (myCircularQueueIsEmpty(obj)) {
         return false;
     }
     CQNode* head = obj->front;
     obj->front = head->next;
     free(head);
     obj->size--;
     return true;
 }
 int myCircularQueueFront(MyCircularQueue* obj) {
     if (myCircularQueueIsEmpty(obj)) {
         return -1;
     }
     return obj->front->data;
 }

 int myCircularQueueRear(MyCircularQueue* obj) {
     if (myCircularQueueIsEmpty(obj)) {
         return -1;
     }
     return obj->tail->data;
 }
 bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
     return obj->size == 0;
 }

 bool myCircularQueueIsFull(MyCircularQueue* obj) {
     return obj->size == obj->k;
 }
 void myCircularQueueFree(MyCircularQueue* obj) {
     CQNode* cur = obj->front;
     while(cur){
         CQNode* next = cur->next;
         free(cur);
         cur = next;
     }

     free(obj);
 }

 /**

 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
   */