#include <iostream>
#include <vector> 
using namespace std;

vector<int> v;
int n,s,count=0;

void solve(int index,int x){
    if(index==n){
        if(x==s){
            count++;
        }
        return;
    }
    solve(index + 1, x); 
	solve(index + 1, x + v[index]);
}


int main()
{
    cin>>n>>s;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    solve(0,0);
    if(s==0) count--;
    cout<<count;
    
    return 0;
}