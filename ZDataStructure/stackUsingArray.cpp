#include<bits/stdc++.h>
using namespace std;

void push(int arr[],int &top,int val,int size){
    if(top==size-1){
        cout<<"Overflow"<<endl;
        return;
    }
    top=top+1;
    arr[top]=val;
}

void pop(int arr[],int& top,int size){
    if(top==-1){
        cout<<"Underflow"<<endl;
        return;
    }
    top=top-1;
}

void printStack(int arr[],int top){
    for(int i=top; i>=0; i--){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    cout<<"Enter the size of Stack: ";
    scanf("%d",&n);
    int top=-1;

    int Stack[n];
    push(Stack,top,10,n);
    push(Stack,top,20,n);
    push(Stack,top,30,n);

    printStack(Stack,top);

    pop(Stack,top,n);

    printStack(Stack,top);


    return 0;
}
