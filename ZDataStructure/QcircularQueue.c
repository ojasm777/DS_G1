#include<stdio.h>
#include<stdlib.h>

struct CQueue{
    int capacity;
    int f;
    int r;
    int* arr;
};

int isFull(struct CQueue *q){
    return (q->r+1)%q->capacity==q->f;
}
void enQueue(struct CQueue *q,int val){
    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }
    if(q->f==-1) q->f=0;
    q->r=(q->r+1)%q->capacity;
    q->arr[q->r]=val;
}

int isEmpty(struct CQueue *q){
    return q->f==q->r==-1;
}

void deQueue(struct CQueue *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    if(q->f==q->r){
        q->f=-1;
        q->r=-1;
        return;
    }
    q->f=(q->f+1)%q->capacity;
}

void display(struct CQueue *q){
    int i=q->f;
    while(1){
        printf("%d ",q->arr[i]);
        if(i==q->r) break;
        i=(i+1)%q->capacity;
    }
    printf("\n");
}

int main(){
    struct CQueue q;
    q.capacity=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.capacity*sizeof(int));

    enQueue(&q,10);
    enQueue(&q,20);
    enQueue(&q,30);
    enQueue(&q,40);

    display(&q);

    deQueue(&q);
    deQueue(&q);
    deQueue(&q);

    display(&q);

    enQueue(&q,10);
    enQueue(&q,20);
    enQueue(&q,30);
    enQueue(&q,100);


    display(&q);

    deQueue(&q);
    deQueue(&q);

    display(&q);

    enQueue(&q,101);
    enQueue(&q,108);
    enQueue(&q,-1);


    display(&q);
    return 0;
}