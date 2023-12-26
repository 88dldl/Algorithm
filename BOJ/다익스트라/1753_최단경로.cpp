#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int v,e,start;
vector<pair<int,int>> road[200001];
int check[200001];

void Dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    check[start]=0;    
    
    while(!pq.empty()){
        int tmpsum=-pq.top().first;
        int now=pq.top().second;
        pq.pop();
        
        if(check[now]<tmpsum)
            continue;
            
        for(int i=0;i<road[now].size();i++){
            int nextDest=road[now][i].first;
            int nextSum=tmpsum+road[now][i].second;
            
            if(check[nextDest]>nextSum){
                check[nextDest]=nextSum;
                pq.push(make_pair(-nextSum,nextDest));
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(check[i]==INF) cout<<"INF\n";
        else cout<<check[i]<<"\n";     
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>v>>e>>start;

    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        road[a].push_back(make_pair(b,c));
    }
    
    for(int i=1;i<=v;i++){
        check[i]=INF;
    }
    
    Dijkstra();
    return 0;
}