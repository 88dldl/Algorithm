#include <iostream>
#include <vector>
 
#define INF 214748300
using namespace std;
 
typedef struct jump {
    int y, x, dist;
};
 
vector<jump> tmp[2501];
long k;
int n,res;
 
int solve(){
    int tmpk = k, res=INF;
     
    for (int i = 1; i <= k; i++) {
        if (tmp[i].empty()) {
            return -1;
        }
    }
     
    while(tmpk>1){
        for(jump j : tmp[tmpk]){
            int x=j.x,y=j.y,dist=j.dist;
            for(jump &item : tmp[tmpk-1]){
                int newdist = (abs(item.y - y) + abs(item.x - x)) + dist;
                item.dist=min(newdist,item.dist);
            }
        }
        tmpk--;
    }
    for(jump j : tmp[1]){
        res=min(j.dist,res);
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     
    int tc;
    cin>>tc;
     
    for(int t=1;t<=tc;t++){
        long num;
        cin>>n>>k;
         
        //타일 입력
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>num;
                if(num!=k) tmp[num].push_back({i,j,INF});
                else tmp[num].push_back({i,j,0});
            }
        }  
         
        int res=solve();
         
        cout<<"#"<<t<<" "<< res << '\n';
         
        for(int i=1;i<=k;i++)
            tmp[i].clear();
    }
    return 0;
}