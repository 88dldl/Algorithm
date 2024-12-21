#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
int visit[1001];
int count=0;

void solve(){
    while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        q.pop();
        count++;
        
        if(second==1){
            visit[first] = count;
            continue;
        }
        q.push(make_pair(first,second-1));
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        q.push(make_pair(i,tmp));
    }
    
    solve();
    
    for(int i=1;i<=n;i++){
        printf("%d ",visit[i]);
    }
    return 0;
}