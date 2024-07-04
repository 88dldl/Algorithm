#include <iostream>
using namespace std;

int n,m;
int visit[1000001];

int find(int x){
    if(visit[x]==x) return x;
    return visit[x] = find(visit[x]);
}

void uni(int a,int b){ 
    int num1 = find(a);
    int num2 = find(b);
    
    visit[num2] = num1;
}

void check(int a,int b){
    if(visit[a]==visit[b]) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    
    for(int i=0;i<=n;i++){
        visit[i]=i;
    }
    
    for(int i=0;i<m;i++){
        int tmp,a,b;
        cin>>tmp>>a>>b;
        if(tmp==0){
            uni(a,b);
        }
        else if(tmp==1){
            find(a);
            find(b);
            check(a,b);
        }
    }
    return 0;
}