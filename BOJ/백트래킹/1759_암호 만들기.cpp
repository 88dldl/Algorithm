#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int l,c;
vector<pair<char,int>> v;
vector<int> tmp,check;
bool visit[16]={false};

void solve(int x){
    if(tmp.size()==l){
        int tmpcheck[2]={0};
        for(int i=0;i<l;i++){
            if(v[tmp[i]].second==1) tmpcheck[0]++;
            else if(v[tmp[i]].second==2) tmpcheck[1]++;
        }
        if(tmpcheck[0]>0 && tmpcheck[1]>1){
            for(int i=0;i<l;i++){
                cout<<v[tmp[i]].first;
            }
        }
        else return;
        
        cout<<"\n";
        return;
    }
    for(int i=x;i<v.size();i++){
        if(!visit[i]){
            visit[i]=true;
            tmp.push_back(i);
            solve(i+1);
            tmp.pop_back();
            visit[i]=false;
        }
    }
}

int main()
{
    cin>>l>>c;
    
    for(int i=0;i<c;i++){
        char tmp;
        int n;
        cin>>tmp;

        if(tmp =='a' || tmp=='e'||tmp=='i'|| tmp=='o'|| tmp=='u') n=1;
        else n=2;
        
        v.push_back({tmp,n});
        
    }
    sort(v.begin(),v.end());
    solve(0);
    return 0;
}