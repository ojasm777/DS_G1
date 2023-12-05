#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int t;
    int capacity;
public:
    Stack(int tsize){
        t=-1;
        arr = new int[tsize];
        capacity = tsize;
    }

    void push(int n){
        if(size() >= capacity){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        t++;
        arr[t]=n;
    }

    int pop(){
        if(size() <=0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        int ele = arr[t];
        t--;
        return ele;
    }

    int size(){
        return t+1;
    }

    int top(){
        if(size() <=0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        return arr[t];
    }

    void display(){
        for(int i=0; i<size(); i++){
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