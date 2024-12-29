#include <iostream>
#include <string>
using namespace std;

int n,ans=-1;
string st,dt,tmp;

void change(int index){
    if(index > 0) tmp[index-1] = (tmp[index-1] == '0') ? '1' : '0';
    tmp[index] = (tmp[index] == '0') ? '1' : '0';
    if(index < n-1) tmp[index+1] = (tmp[index+1] == '0') ? '1' : '0';
}

void solve(int first){
    int count=0;
    tmp=st;

    if(first==0){
        tmp[0]=(tmp[0]=='0')?'1':'0';
        tmp[1]=(tmp[1]=='0')?'1':'0';
        count++;
    }
    
    for(int i=1;i<n;i++){
        if(tmp[i-1]!=dt[i-1]){
            change(i);
            count++;
        }
    }
    
    if(tmp==dt) {
        if(ans==-1) ans=count;
        else{ans=min(ans,count);}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    cin>>st>>dt;
    
    solve(0);
    solve(1);

    cout<<ans;

    return 0;
}