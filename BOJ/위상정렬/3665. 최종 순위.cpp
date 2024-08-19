#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


int n,m;
vector<int> r;
vector<int> map[501];

void solve(){
    queue<int> q;
    vector<int> result;
    
    bool findthing = false;
    
    for(int i=1;i<=n;i++){ 
        if(r[i]==0) q.push(i);
    }

    while(!q.empty()){
        if(q.size() > 1) {
            findthing = true;
            break;
        }
        int now = q.front();
        q.pop();
        result.push_back(now);
        
        for(int tmpmap : map[now]){
            r[tmpmap]--;
            if(r[tmpmap]==0){
                q.push(tmpmap);
            }
        }
    }
    if(findthing) cout<<"?\n";
    else if(result.size()!=n) cout<<"IMPOSSIBLE\n";
    else{
        for(int i=0;i<n;i++){
            cout<<result[i]<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    
    while(t--){
        cin>>n;
        bool v[501];
        memset(v, false, sizeof(v));
        r.assign(n+1,0);
        for(int i=0;i<=501;i++) map[i].clear();
        
        for(int i=0;i<n;i++){
            int tmp;
            cin>> tmp;
            v[tmp]=true;
            for(int j=1;j<=n;j++){
                if(!v[j]){
                    map[tmp].push_back(j);
                    r[j]++;
                }
            }
        }
        
        cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            vector<int>::iterator it = find(map[y].begin(), map[y].end(), x);
          
            if(it!= map[y].end()){
                map[y].erase(it);
                map[x].push_back(y);
                r[x]--;
                r[y]++;
            } else{
                it = find(map[x].begin(), map[x].end(), y);
                map[x].erase(it);
                map[y].push_back(x);
                r[x]++;
                r[y]--;
            }
           
        }
        solve();
        
    }
    return 0;
}