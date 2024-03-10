#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n,maxnum,node1;
vector<int> v[51],num[51];
queue<pair<int,int>> q;
vector<bool> visit(51);

void solve(){ 
    q.push({node1,0});
    visit[node1]=true;
    
    while(!q.empty()){
        int tmp = q.front().first; 
        int countnum = q.front().second; 
        q.pop();
    
        for(int i=0;i<v[tmp].size();i++){
            if(!visit[v[tmp][i]]){  
                visit[v[tmp][i]]=true; 
                q.push({v[tmp][i],countnum+1});
            }
        }
        
        if(n == count(visit.begin(), visit.end(), true)) {
            maxnum = q.back().second;
            break;
        }
    }
    return;
}


int main()
{
    int x,y;
    
    //입력
    cin>>n;
    cin>>x>>y;
    while(x!=-1){
        v[y].push_back(x);
        v[x].push_back(y);
        cin>>x>>y;
    }
    
    //solve
    for(int i=1;i<=n;i++){
        maxnum=0;
        fill(visit.begin(),visit.end(),false);
        q = queue<pair<int,int>>();
        node1=i;
        solve();
        num[maxnum].push_back(i);
    }
    
    //출력
    for(int i=1;i<=n;i++){
        if(num[i].size()>0){
            cout<<i<<" "<<num[i].size()<<"\n";
            for(int j=0;j<num[i].size();j++){
                cout<<num[i][j]<<" ";
            }
            break;
        }
    }
    return 0;
}