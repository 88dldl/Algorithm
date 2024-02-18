#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<int> v[21];
vector<int> q;
bool visit[21]={false};
int sum1=0,sum2=0;
int minnum = 100000000;

void power(){
    sum1=0,sum2=0;
    for(int i=0;i<n;i++){
        if(visit[i]){
            for(int j=0;j<n;j++){
                if(visit[j]) sum1+=v[i][j];
            }
        }
        else{
            for(int j=0;j<n;j++){
                 if(!visit[j]) sum2+=v[i][j];
            }
        }
    }
    return;
}

void solve(int x){
    if(q.size()==n/2){
        power();
        minnum = min(minnum,abs(sum1-sum2));
        return;
    }
    for(int i=x;i<n;i++){
        if(!visit[i]){
            visit[i]=true;
            q.push_back(i);
            solve(i+1);
            q.pop_back();
            visit[i]=false;
        }    
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            cin>>tmp;
            v[i].push_back(tmp);
        }
    }
    solve(0);
    
    cout<<minnum;

    return 0;
}