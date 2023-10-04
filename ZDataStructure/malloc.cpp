// #include<bits/stdc++.h>
#include<iostream>
// #include<stdio.h>
// #include<stdlib.h>

using namespace std;

int main(){
    int* ptr;
    ptr=(int*) malloc(4*(sizeof(int)));
    ptr[0]=10;
    ptr[1]=20;
    ptr[2]=30;
    ptr[3]=40;
    for(int i=0; i<4; i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;

    int* ptr2;
    ptr2=new int[10];
    for(int i=0; i<10; i++){
        ptr2[i]=(i+1)*10;
    }
    for(int i=0; i<10; i++){
        cout<<ptr2[i]<<" ";
    }

    return 0;
}