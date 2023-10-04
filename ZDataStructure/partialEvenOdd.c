#include<stdio.h>

void partialEvenOdd(int* arr,int size){
    int i=0,j=size-1;
    while(i<=j){
        if(arr[i]%2==0) i++;
        else if(arr[j]%2!=0) j--;
        else if(arr[i]%2!=0 && arr[j]%2==0){
        // else{
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
}

int main(){
    int arr[]={1,2,3,4,10,22,9};

    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    partialEvenOdd(arr,7);

    for(int i=0; i<7; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}