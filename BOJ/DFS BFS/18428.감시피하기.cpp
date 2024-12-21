#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> t,x;
char corridor[6][6];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int n;

bool check(int x,int y){
    for(int i = 0; i < 4; i++) {
		int nrow = x;
		int ncol = y;
		while(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n) {
			nrow += dx[i];
			ncol += dy[i];
			if(corridor[nrow][ncol] == 'O')
				break;
			if(corridor[nrow][ncol] == 'S')
				return false;
		}
	}
	return true;
}

void dfs(int index,int count){
    if(count==3){
        for(auto element : t){
            if(!check(element.first,element.second)) return;
        }
        cout<<"YES\n";
        exit(0);
    }
    
    for(int i=index;i<x.size();i++){
        corridor[x[i].first][x[i].second]='O';
        dfs(i+1,count+1);
        corridor[x[i].first][x[i].second]='X';
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>corridor[i][j];
            if(corridor[i][j]=='T'){
                t.push_back({i,j});
            }
            if(corridor[i][j]=='X'){
                x.push_back({i,j});
            }
        }
    }

    dfs(0,0);
    cout << "NO\n";
    
    return 0;
}