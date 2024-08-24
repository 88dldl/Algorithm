#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<double,double>> v;
int parent[101];
vector<pair<double, pair<int, int>>> edges;
double result=0.0;

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    int tmpx = find(x);
    int tmpy = find(y);
    if(tmpx!=tmpy){
        parent[tmpy] = tmpx;
    }
}
void solve(){
    for (auto edge : edges) {
        double cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
    
        if (find(u) != find(v)) {
            uni(u, v);
            result += cost;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    
    for(int i = 0; i < n; i++) {
        int x = v[i].first;
        int y = v[i].second;
        
        for(int j = i+1; j < n; j++) {
            if(j==i) continue;
            double starcount = sqrt(pow(x - v[j].first, 2) + pow(y - v[j].second, 2));
            edges.push_back({starcount,{i,j}});
        }
    }
    sort(edges.begin(),edges.end());
    
    solve();
    
    cout << fixed;
    cout.precision(2);
    cout<<result;
    return 0;
}