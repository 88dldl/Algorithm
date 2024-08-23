#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<pair<int,pair<int,int>>> v;
vector<pair<int, int>> line[1001];
int n,k,cost =0,maxroute=-1;
int parent[1001];
bool check[1001];

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b) {
    return a.first < b.first;
}

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

void findroute(int x,int y){
    check[x]=true;
    maxroute = max(maxroute,y);
    
    for(int i=0;i<line[x].size();i++){
        int a = line[x][i].first;
        int nextcost = y+ line[x][i].second;
        if(!check[a]) findroute(a,nextcost);
    }
}

void solve(){
    for(int i=0;i<v.size();i++){
        int c = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;
            
        int x = find(a);
        int y = find(b);
        
        if(x!=y){
            parent[x] = y;
            cost += c;
            line[a].push_back({b,c});
            line[b].push_back({a,c});
        }
    }
    cout<<cost<<"\n";
    
    for(int i = 0; i <n; i++){
		memset(check, 0, sizeof(check));
		findroute(i, 0);
	}
	cout<<maxroute<<"\n";
}


int main()
{
    cin>>n>>k;
    for(int i=0;i<k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c,{a,b}});
    }
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    sort(v.begin(),v.end(),cmp);
    
    solve();
    
    return 0;
}