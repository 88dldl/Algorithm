#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[10001];

int find(int x){
    if(parent[x]==x) return x;
    else return parent[x] = find(parent[x]);
}

void uni(int x,int y){
    int tmpx = find(x);
    int tmpy = find(y);
    
    parent[tmpy] = tmpx;
}


int main()
{
    int v,e;
    cin>>v>>e;
    
    vector<pair<int, pair<int, int>>> edge;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({c,{a,b}});
    }

    sort(edge.begin(),edge.end());
    
    for(int i=0;i<v;i++){
        parent[i]=i;
    }
    
    int result =0;
    for(int i=0;i<edge.size();i++){
        int weight = edge[i].first;
        int firstnum = edge[i].second.first;
        int secondnum = edge[i].second.second;
        
        if(find(firstnum)!=find(secondnum)){
            uni(firstnum,secondnum);
            result+=weight;
        }
    }
    cout<<result;
    return 0;
}
