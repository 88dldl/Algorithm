#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long health=-1;
vector<long> v;

void solve(){
    int tmpn=n;
    long tmpnum;
    if(n%2==1){
        tmpn=n-1;
    }
    for(int i=0;i<tmpn/2;i++){
        tmpnum=v[i]+v[tmpn-i-1];
        health=max(tmpnum,health);
    }    
    if(n%2==1){
        health=max(v[n-1],health);
    }
    cout<<health;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        long tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    solve();    
    return 0;
}