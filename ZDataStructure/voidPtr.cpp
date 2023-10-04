#include<bits/stdc++.h>
using namespace std;



int main(){
    void* ptr;
    int n=10;
    ptr=&n;
    cout<<*((int*)ptr);
    return 0;
}