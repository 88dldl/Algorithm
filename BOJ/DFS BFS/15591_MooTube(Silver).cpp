#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,long long>> graph[5000];
int n,Q;

void bfs(long long k, int v){
    vector<int> visit(n + 1, false);
    visit[v] = true;
    
    int count =0;
    queue<int> q;
    q.push(v);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for (auto &edge : graph[now]) {
            int next = edge.first;
            long long weight = edge.second;

            if (!visit[next] && weight >= k) {
                visit[next] = true;
                count++;
                q.push(next);
            }
        }
    }
    cout<<count<<"\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>Q;
    for(int i=0;i<n-1;i++){
        int p,q;
        long long r;
        cin>>p>>q>>r;
        graph[p].emplace_back(q, r);
        graph[q].emplace_back(p, r);
    }
    
    for(int i=0;i<Q;i++){
        int k,v;
        cin>>k>>v;    
        bfs(k,v);
    }
    return 0;
}
