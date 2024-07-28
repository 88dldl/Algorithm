#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t;
vector<int> v,q;
bool visit[13];

void solve(int x){
    if(q.size()==6){
        for(int i=0;i<6;i++){
            cout<<q[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=x;i<t;i++){
        if(!visit[i]){
            visit[i]=true;
            q.push_back(v[i]);
            solve(i);
            visit[i]=false;
            q.pop_back();
        }
    }
}

int main()
{
    cin>>t;
    while(t!=0){
        v = vector<int>();
        for(int i=0;i<t;i++){
            int tmp;
            cin>>tmp;
            v.push_back(tmp);
        }
        solve(0);
        cout<<"\n";
        cin>>t;
    }
    return 0;
}