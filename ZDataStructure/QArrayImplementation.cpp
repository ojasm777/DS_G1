#include<bits/stdc++.h>
using namespace std;

struct Queue{
    int size;
    int f;
    int r;
    int* arr; // dynamically allocating memory for arr
};
bool isFull(struct Queue &q){
    return q.r==q.size-1;
}

bool isEmpty(struct Queue &q){
    return q.f==q.r;
}

void enQueue(struct Queue &q,int val){
    if(isFull(q)){
        cout<<"Queue overflow!"<<endl;
        return;
    }
    q.r++;
    q.arr[q.r]=val;
}

void deQueue(struct Queue &q){
    if(isEmpty(q)){
        cout<<"Queue underflow!"<<endl;
        return;
    }
    q.f++;
}

int top(struct Queue &q){
    return q.arr[q.f+1];
}

void display(struct Queue &q){
    for(int i=q.f+1; i<=q.r; i++){
        cout<<q.arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    struct Queue q;
    q.size=10;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    enQueue(q,10);
    enQueue(q,20);
    enQueue(q,30);
    enQueue(q,40);

    display(q);

    deQueue(q);
    display(q);

    cout<<top(q);

    return 0;
}