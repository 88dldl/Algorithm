#include <iostream>
#include <algorithm>
using namespace std;

int r,c,maxnum= -1;
char word[21][21];
bool visit[21];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

void solve(int x,int y, int count){
    maxnum = max(maxnum,count);

    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && nx<r && ny>=0 && ny<c){
            if(!visit[word[nx][ny]-'A']){
                visit[word[nx][ny]-'A']=true;
                solve(nx,ny,count+1);
                visit[word[nx][ny]-'A']=false;
            }
        }
    }
} 

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>word[i][j];
        }
    }

    visit[word[0][0]-'A']=true;
    solve(0,0,1);

    cout<<maxnum;
    return 0;
}