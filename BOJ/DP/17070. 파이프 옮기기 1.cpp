#include <iostream>
#include <algorithm>
using namespace std;

int pipe[18][18];
int v[3][18][18]={0};
int n;

void solve(){ 
    v[0][0][1]=1;

    for(int i=2;i<n;i++){
        if(pipe[0][i] == 0)
            v[0][0][i] = v[0][0][i - 1];
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(pipe[i][j]!=1){
                v[0][i][j]+=v[0][i][j-1]+v[2][i][j-1]; //가로
                v[1][i][j]+= v[1][i-1][j]+v[2][i-1][j];//세로
                if(pipe[i-1][j]!=1 && pipe[i][j-1]!=1)
                    v[2][i][j]= v[0][i-1][j-1]+v[2][i-1][j-1]+v[1][i-1][j-1];//대각선
            }
        }
    }
    
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>pipe[i][j];
        }
    }
    solve();
    int sumv = v[0][n-1][n-1]+v[1][n-1][n-1]+v[2][n-1][n-1];
    cout<<sumv;
    return 0;
}