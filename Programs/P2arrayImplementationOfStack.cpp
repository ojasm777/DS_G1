#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    int *arr;
    int t;
    int capacity;

    Stack(int tSize){
        arr=new int[tSize];
        t=0;
        capacity=tSize;
    }

    void push(int val){
        if(size()==capacity){
            cout<<"Overflow"<<endl;
            return;
        }
        arr[t]=val;
        t++;
    }

    void pop(){
        if(size()==0){
            cout<<"Underflow"<<endl;
            return;
        }
        t--;
    }

    int size(){
        return t;
    }

    int top(){
        if(size()==0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[t-1];
    }

    void display(){
        for(int i=0; i<t; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Stack st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.display();
    st.pop();
    st.pop();
    st.display();
    st.push(100);
    st.display();

    return 0;
}