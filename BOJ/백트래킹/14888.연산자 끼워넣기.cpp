#include <iostream>
#include <algorithm>
using namespace std;

int ope[4],num[101];
int n,maxnum=-1000000001,minnum=1000000001;

void solve(int result, int index){
    if(index==n){
        maxnum = max(maxnum,result);
        minnum =min(minnum,result);
        return;
    }
    for(int i=0;i<4;i++){
        if(ope[i]>0){
            ope[i]--;
            if(i==0) solve(result+num[index],index+1);
            else if(i==1) solve(result-num[index],index+1);
            else if(i==2) solve(result*num[index],index+1);
            else solve(result/num[index],index+1);
            ope[i]++;
        }
    }
        
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<4;i++){
        cin>>ope[i];
    }
    solve(num[0],1);
    cout<<maxnum<<"\n"<<minnum;
    return 0;
}