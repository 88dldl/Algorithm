#include <iostream>
#include <queue>
#include <vector> 
#include <cstring>
using namespace std;

int n,m,start,dest;
vector<pair<int,int>> v[1001];
vector<int> visit_v;
priority_queue<pair<int,int>> pq;
int check[1001];
int visit[1001];

void Dijkstra(){
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,start));
    check[start]=0;

    while(!pq.empty()){
        int count=-pq.top().first;
        int now=pq.top().second;
        
        pq.pop();
        
        if(check[now]<count) 
            continue;
        
        for(int i=0;i<v[now].size();i++){
            int next= v[now][i].first;
            int tmpcount = count+v[now][i].second;
            
            if(check[next]>tmpcount){
                visit[next]=now;
                check[next]=tmpcount;
                pq.push(make_pair(-tmpcount,next));
            }
        }
    }
    
    cout<<check[dest]<<endl;
   
    int tmp=dest;
    while(tmp){
        visit_v.push_back(tmp);
        tmp=visit[tmp];    
    }
    cout<<visit_v.size()<<endl;
    for(int i=visit_v.size()-1;i>=0;i--){
        cout<<visit_v[i]<<" ";
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back(make_pair(b,c));
    }
    cin>>start>>dest;
    
    memset(check, 98765432, sizeof(check));
    
    Dijkstra();
    return 0;
}