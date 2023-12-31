#include <iostream>
#include <queue>
using namespace std;

int n,k;
int visit[100001];

void bfs(){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> q;
    q.push(make_pair(0,n));
    
    while(!q.empty()){
        int count=q.top().first;
        int nx=q.top().second;
        q.pop();
        
        visit[nx]=1;


        if(nx==k){
            cout<<count;
            break;
        }
        
        if(nx-1>=0 &&!visit[nx-1])
            q.push(make_pair(count+1,nx-1));
        if(nx+1<=100000 && !visit[nx+1])
			q.push(make_pair(count+1,nx+1));
		if(nx*2<=100000 && !visit[nx*2])
			q.push(make_pair(count,nx*2));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>k;
    bfs();
    
    return 0;
}