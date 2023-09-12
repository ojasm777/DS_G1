// Implement queue using array
#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int f;
    int b;
    int capacity;
public:
    Queue(int size){
        // vector<int> v(size);
        arr= new int[size];
        capacity=size;
        f=0;
        b=0;
    }

    void enqueue(int val){
        if(size()==capacity){
            cout<<"Overflow!"<<endl;
            return;
        }
        arr[b]=val;
        b++;
    }

    void dequeue(){
        if(size()==0){
            cout<<"Underflow!"<<endl;
            return;
        }
        f++;
    }

    int front(){
        if(size()==0){
            cout<<"Underflow!"<<endl;
            return -1;
        }
        return arr[f];
    }

    bool empty(){
        return size()==0;
    }

    int size(){
        return b-f;
    }

    void display(){
        for(int i=f; i<b; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
public:

};

int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.display();
    return 0;
}