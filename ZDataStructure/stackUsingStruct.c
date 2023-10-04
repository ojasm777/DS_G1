#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int* arr;
    int top;
    int size;
};

void push(struct Stack* st,int val){
    if(st->top==st->size-1){
        printf("Overflow!\n");
        return;
    }
    st->top++;
    st->arr[st->top]=val;
}

void pop(struct Stack* st){
    if(st->top==-1){
        printf("Underflow!\n");
        return;
    }
    st->top--;
}

void printStack(struct Stack* st){
    for(int i=st->top; i>=0; i--){
        printf("%d ",st->arr[i]);
    }
    printf("\n");
}

int main(){
    struct Stack *st;
    scanf("%d",&st->size);
    st->arr=(int*)malloc(st->size*sizeof(int));
    // for(int i=0; i<st->size; i++){
    //     scanf("%d",st->arr[i]);
    // }

    push(st,10);
    push(st,20);
    push(st,30);
    push(st,40);

    printStack(st);

    pop(st);


    printStack(st);

    push(st,40);
    push(st,50);



    return 0;
}