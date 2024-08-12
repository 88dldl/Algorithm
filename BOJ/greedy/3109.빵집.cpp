#include <iostream>
using namespace std;

int r,c,count=0;
char map[10001][501];
int dx[3] = {1,1,1};
int dy[3] = {-1, 0, 1};
bool check;

void solve(int y,int x){ 
    if(x == c-1){
        check = true;
        count++;
        return;
    } 
    
    map[y][x]='x';

    for(int i=0;i<3;i++){
        int tmpy = dy[i]+y;
        int tmpx = dx[i]+x;
        if(tmpx<0 || tmpx>=c || tmpy<0 || tmpy>=r || map[tmpy][tmpx]=='x') continue;
        solve(tmpy,tmpx);
        if(check) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>> map[i][j];
        }
    }
    for(int i=0;i<r;i++){
        check = false;
        solve(i,0);
    }

    cout<<count;
    return 0;
}