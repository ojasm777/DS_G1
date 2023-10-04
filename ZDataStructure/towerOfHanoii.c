#include<stdio.h>

void towerOfHanoi(int n,char A,char B,char C){
    if(n==0) return;
    towerOfHanoi(n-1,A,C,B);
    printf("%c -> %c\n",A,C);
    towerOfHanoi(n-1,B,A,C);
}

int main(){
    towerOfHanoi(3,'A','B','C');
    return 0;
}