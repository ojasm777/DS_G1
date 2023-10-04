#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n,char source, char auxiliary, char destination){
    if(n==0) return;
    //step I
    towerOfHanoi(n-1,source,destination,auxiliary);
    cout<<source<<" -> "<<destination<<endl;
    towerOfHanoi(n-1,auxiliary,source,destination);

}

int main(){
    towerOfHanoi(3,'A','B','C');
    return 0;
}