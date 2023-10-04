#include<stdio.h>

int main(){
    int* arr[3];
    int x=10,y=20,z=30;
    int*p=&x,*q=&y,*r=&z;
    arr[0]=p;
    arr[1]=q;
    arr[2]=r;
    for(int i=0; i<3; i++){
        printf("%d ",*arr[i]);
    }
    printf("\n");
    for(int i=0; i<3; i++){
        if(arr[i]==&x) printf("1");
    }
    return 0;
}