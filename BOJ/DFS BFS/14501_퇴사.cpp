#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n,maxm=0;
vector<pair<int,int>> v;
vector<int> tmp;
bool visit[15]={false};

void solve(int next){
    int tmpsum = accumulate(tmp.begin(),tmp.end(),0);
    maxm=max(maxm,tmpsum);
    
    for(int i=next;i<n;i++){
        if(!visit[i] && v[i].first>0){
            int s = v[i].first;
            int money = v[i].second;
            visit[i]=true;
            tmp.push_back(v[i].second);
            solve(i+s); 
            visit[i]=false;
            tmp.pop_back();
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(i+x>n) v.push_back({-1,y});
        else v.push_back({x,y});
    }
    solve(0);
    cout<<maxm;
    return 0;
}