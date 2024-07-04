#include <iostream>
using namespace std;

int visit[201];

int find(int x){
    if(visit[x]==x) return x;
    return visit[x] = find(visit[x]);
}

void uni(int x,int y){
    int num1 = find(x);
    int num2 = find(y);
    
    if(num1<num2) visit[num2]=num1;
    else visit[num1]=num2;
}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m,f,s,t,root;
    cin>>n>>m;
    
    for(int i=1;i<=n;i++){
        visit[i]=i;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(i>=j) continue;
            if(x==1){ 
                uni(i,j);
                
            }
        }
    }

    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        if(i==0) root = find(tmp);
        else{
            if(find(root)!=find(tmp)){
                cout<<"NO"<<"\n";
                return 0;
            }
        }
    }
    
    cout<<"YES"<<"\n";
    return 0;
}