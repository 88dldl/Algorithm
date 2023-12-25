#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> bus[1001];
int start,dest;
int check[1001];

void Dijkstra(){
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0,start)); 
    check[start]=0;

    while(!pq.empty()){
        int sum=pq.top().first;
        int now=pq.top().second;
        
        pq.pop();

        if(check[now]<sum)
            continue;
        
        for(int i=0;i<bus[now].size();i++){
            int nextDest=bus[now][i].first;
            int nextSum=sum+bus[now][i].second;
            
            if(check[nextDest]>nextSum){
                check[nextDest]=nextSum;
                pq.push(make_pair(nextSum,nextDest));
            }
        }
    }

    cout<<check[dest]<<endl;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    memset(check, 98765432, sizeof(check));
    
    for(int i=0;i<m;i++){
        int tmpS,tmpD,tmpM;
        cin>>tmpS>>tmpD>>tmpM;
        
        bus[tmpS].push_back(make_pair(tmpD,tmpM));
    }

    cin>>start>>dest;
    Dijkstra();
    
    return 0;
}