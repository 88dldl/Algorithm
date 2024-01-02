#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n,m,x;
vector<pair<int,int>> v[2][1001];
vector<int> visit_v;
int visit[2][1001];

void Dijkstra(int start){
    visit[start][x]=0;

    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,x));

    while(!pq.empty()){
        int count = -pq.top().first;
        int now = pq.top().second;
    
        pq.pop();
    
        if(visit[start][now]<count)
            continue;
        
        for(int i=0;i<v[start][now].size();i++){
            int next = v[start][now][i].first;
            int nextcount=v[start][now][i].second+count;
            
            if(visit[start][next]>nextcount){
                visit[start][next]=nextcount;
                pq.push(make_pair(-nextcount,next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>x;
    
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[0][a].push_back(make_pair(b,c));
        v[1][b].push_back(make_pair(a,c));
    }
    
    memset(visit[0], 98765432, sizeof(visit[0]));
    memset(visit[1], 98765432, sizeof(visit[1]));

    Dijkstra(0);
    Dijkstra(1);
        
    int Max=0;
    for(int i=1;i<=n;i++){
        Max=max(Max,visit[0][i]+visit[1][i]);
    }
    cout<<Max;
    return 0;
}