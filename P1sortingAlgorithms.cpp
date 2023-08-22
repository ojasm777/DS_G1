#include<bits/stdc++.h>
using namespace std;

void display(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        bool flag=1;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
            flag=0;
        }
        if(flag==1) break;
    }
    display(arr,n);
}

void selectionSort(int arr[],int n){
    for(int i=0; i<n-1; i++){
        int minEle=INT_MAX;
        int minIn=-1;
        for(int j=i; j<n; j++){
            if(arr[j]<minEle){
                minEle=arr[j];
                minIn=j;
            }
        }
        swap(arr[i],arr[minIn]);
    }
    display(arr,n);
}

void insertionSort(int arr[],int n){
    for(int i=1; i<n; i++){
        for(int j=i; j>=1 && arr[j]<arr[j-1]; j--) swap(arr[j],arr[j-1]);
    }
    display(arr,n);
}

int main(){
    int n;
    cout<<"Enter the size of arr: ";
    cin>>n;

    int arr[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"1.Bubble Sort"<<endl;
    cout<<"2.Selection Sort"<<endl;
    cout<<"3.Insertion Sort"<<endl;
    cout<<"Enter the sorting algorithm of your choice: ";
    int choice;
    cin>>choice;

    switch(choice){
        case 1:
            bubbleSort(arr,n);
            break;
        case 2:
            selectionSort(arr,n);
            break;
        case 3:
            insertionSort(arr,n);
            break;
        default:
            cout<<"Wrong input"<<endl;
    }
    return 0;
}