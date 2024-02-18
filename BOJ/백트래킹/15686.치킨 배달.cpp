#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 2147483647

using namespace std;

int n,m;
int minsum = MAX_INT;
vector<pair<int,int>> v[3],test;
bool visit[51]={false};

void chicken(){
    int tmpsum=0;

    for(int i=0;i<v[1].size();i++){
        int sumof=100; 
        for(int j=0;j<m;j++){
            sumof=min(sumof,abs(test[j].first-v[1][i].first)+abs(test[j].second-v[1][i].second));
        }
        tmpsum+=sumof;
    }    

    minsum=min(minsum,tmpsum);
    return;
}

void solve(int x){
    if(test.size()==m){
        chicken();
        return;
    }

    for(int i=x;i<v[2].size();i++){
        if(!visit[i]){
            visit[i]=true;
            test.push_back(v[2][i]);
            solve(i+1);
            test.pop_back();
            visit[i]=false;
        }
    }
    
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            v[tmp].push_back(make_pair(i,j)); 
        }
    }
    
    solve(0);
    cout<<minsum;
    return 0;
}