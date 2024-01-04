#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
typedef long long ll;

using namespace std;

int n,m,k;
vector<pair<ll,int>> v[100001];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
vector<ll> dest;
ll visit[100001];

void Dijkstra(){
    ll Max=0,maxdest=0;

    while(!pq.empty()){
        ll count=pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        
        if(visit[now]<count) continue;
        
        for(int i=0;i<v[now].size();i++){
            int next=v[now][i].first;
            ll nextcount=count+v[now][i].second;
            
            if(visit[next]>nextcount){
                visit[next]=nextcount;
                pq.push(make_pair(nextcount,next));
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(Max<visit[i]){
            Max=visit[i];
            maxdest=i;
        }
    }
    cout<<maxdest<<"\n"<<Max;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>k;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[b].push_back(make_pair(a,c));
    }
    
    memset(visit,98765432,sizeof(visit));

    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        pq.push(make_pair(0,tmp));
        visit[tmp]=0;
    }

    Dijkstra();
    
    return 0;
}