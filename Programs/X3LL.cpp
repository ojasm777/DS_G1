#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{
    ListNode* head;
    ListNode* tail;
public:
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtHead(int val){
        ListNode* node = new ListNode(val);
        if(size==0) head = tail = node;
        else{
            node->next = head;
            head = node;
        }
        size++;
    }

    void insertAtTail(int val){
        ListNode* node = new ListNode(val);
        if(size==0) head = tail = node;
        else{
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void insertAtIndex(int val,int idx){
        ListNode* node = new ListNode(val);
        if(size==0) insertAtHead(val);
        if(size==idx) insertAtTail(val);
        if(idx<0 || idx>size){
            cout<<"Wrong input"<<endl;
            return;
        }
        ListNode* temp = head;
        for(int i=0; i<idx-1; i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
        size++;
    }

    void deleteAtHead(){
        if(size<=0){
            cout<<"Size is 0"<<endl;
            return;
        }
        if(size==1){
            tail = head = NULL;
            size--;
            return;
        }
        head = head->next;
        size--;
    }

    void deleteAtTail(){
        if(size<=0){
            cout<<"Size is 0"<<endl;
            return;
        }
        if(size==1){
            tail = head = NULL;
            size--;
            return;
        }
        ListNode* temp = head;
        while(temp->next!=tail){
            temp = temp->next;
        }
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIdx(int idx){
        if(size==0){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(idx == 0) deleteAtHead();
        if(idx == size-1) deleteAtTail();
        ListNode* temp = head;
        for(int i=0; i<idx-1; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        size--;
    }

    void display(){
        ListNode* temp = head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    LinkedList ll;
    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.display();
    ll.insertAtIndex(15,1);
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    cout<<ll.size<<endl;
    ll.insertAtIndex(14,1);
    ll.insertAtTail(100);
    ll.display();
    ll.deleteAtIdx(2);
    ll.display();

    return 0;
}
