#include <iostream>
#include <vector>
using namespace std;

int visit[51];
vector<int> v[51];


int find(int x){
    if(visit[x]==x) return x;
    return visit[x] = find(visit[x]);
}

void uni(int x,int y){
    int num1 = find(x);
    int num2 = find(y);
    
    if(num1<num2) visit[num2] = num1;
    else visit[num1] = num2;
}

int main()
{
    int n,m,p,root=0;
    cin>>n>>m>>p;
    for(int i=0;i<=n;i++){
        visit[i]=i;
    }

    int tmpm = m;
    
    for(int i=0;i<p;i++){
        int x;
        cin>>x;
        if(i==0) root = x;
        else uni(root,x);
    }
    
    for(int i=0;i<m;i++){
        int x,root2=0;
        cin>>x;
    
        for(int j=0;j<x;j++){
            int tmp ; 
            cin>>tmp;
            v[i].push_back(tmp);
            if(j==0) root2=find(tmp);
            else{
                uni(root2,tmp);
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<v[i].size();j++){
            if(find(root)==find(v[i][j])){
                tmpm--;
                break;
            }
        }
    }

    cout<<tmpm;
    
    
    return 0;
}