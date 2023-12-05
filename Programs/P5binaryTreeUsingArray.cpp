#include<iostream>
#include<climits>

using namespace std;

class BinaryTree{
    int *arr;
    int size;
    int capacity;
    public:
        BinaryTree(int n){
            arr = new int[n];
            capacity=n;
            size=0;
        }
        void rootNode(int val){
            arr[0]=val;
            size++;
        }
        void insertLeftChild(int idx, int val){
            int pi = idx;
            int ci = 2*pi+1;
            if(ci >= capacity){
                cout<<"Wrong index";
                return;
            }
            arr[ci]=val;
            size++;
        }
        void insertRightChild(int idx, int val){
            int pi = idx;
            int ci = 2*pi+2;
            if(ci >= capacity){
                cout<<"Wrong index";
                return;
            }
            arr[ci]=val;
            size++;
        }
        void print(){
            for(int i=0; i<size; i++){
                if(arr[i]!=INT_MIN) cout<<arr[i]<<" ";
                else cout<<"NULL ";
            }
            cout<<endl;
        }
        void preorder(int idx){
            if(idx>=size) return;
            if(arr[idx]==INT_MIN) cout<<"NULL ";
            else cout<<arr[idx]<<" ";
            int r=idx;
            int lc=2*r+1;
            int rc=2*r+2;
            preorder(lc);
            preorder(rc);
        }
        void inorder(int idx){
            if(idx>=size) return;
            int r=idx;
            int lc=2*r+1;
            int rc=2*r+2;
            inorder(lc);
            if(arr[idx]==INT_MIN) cout<<"NULL ";
            else cout<<arr[idx]<<" ";
            inorder(rc);
        }
        void postorder(int idx){
            if(idx>=size) return;
            int r=idx;
            int lc=2*r+1;
            int rc=2*r+2;
            postorder(lc);
            postorder(rc);
            if(arr[idx]==INT_MIN) cout<<"NULL ";
            else cout<<arr[idx]<<" ";
        }

};

int main(){
    BinaryTree bt(10);
    bt.rootNode(10);
    bt.insertLeftChild(0,20);
    bt.insertRightChild(0,-1);
    bt.insertLeftChild(1,25);
    bt.insertRightChild(1,19);
    bt.insertLeftChild(2,INT_MIN);
    bt.insertRightChild(2,5);
    cout<<"Preorder: ";
    bt.preorder(0);
    cout<<endl;
    cout<<"Inorder: ";
    bt.inorder(0);
    cout<<endl;
    cout<<"Postorder: ";
    bt.postorder(0);

    return 0;
}