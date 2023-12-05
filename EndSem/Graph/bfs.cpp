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

    // Breadth first search implementation
    // adjacency matrix
    int u;
    int i = 0;// start from 0
    int visited[] = {0,0,0,0,0,0,0};
    int arr[7][7] = {
       {0,1,1,1,0,0,0},
       {1,0,0,1,0,0,0},
       {1,0,0,1,1,0,0},
       {1,1,1,0,1,0,0},
       {0,0,1,1,0,1,1},
       {0,0,0,0,1,0,0},
       {0,0,0,0,1,0,0}
    };
    printf("%d ", i);
    visited[i] = 1;
    enQueue(q,i);
    while(!isEmpty(q)){
        int first = top(q);
        deQueue(q);
        for(int j=0; j<7; j++){
            if(arr[first][j]==1 && visited[j]!=1){
                printf("%d ", j);
                visited[j] = 1;
                enQueue(q,j);
            }
        }
    }

    return 0;
}