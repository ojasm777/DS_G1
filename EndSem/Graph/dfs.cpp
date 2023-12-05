#include<bits/stdc++.h>
using namespace std;

int visited[] = {0,0,0,0,0,0,0};
int arr[7][7] = {
   {0,1,1,1,0,0,0},
   {1,0,0,1,0,0,0},
   {1,0,0,1,1,0,0},
   {1,1,1,0,1,0,0},
   {0,0,1,1,0,1,1},
   {0,0,0,0,1,0,0},
   {0,0,0,0,1,0,0}
};

void DFS(int i){
    printf("%d ",i);
    visited[i] = 1;
    for(int j=0; j<7; j++){
        if(arr[i][j]==1 && visited[j]!=1){
            DFS(j);
        }
    }
}

int main(){
    // Depth first search implementation
    DFS(0);
    return 0;
}