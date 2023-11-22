#include <iostream>

using namespace std;
int n;
int queen[16];
int count=0;


bool promising(int x){
    for(int i=0;i<x;i++){
        if(queen[i]==queen[x] || abs(x-i)==abs(queen[x]-queen[i]))
            return false;
    }
    return true;
}

void NQueen(int x){
    if(x==n){
        count++;
        return;
    }
    for(int i=0;i<n;i++){
        queen[x]=i;
        if(promising(x)){
            NQueen(x+1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    NQueen(0);
    
    cout<<count;
    return 0;
}