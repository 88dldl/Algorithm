#include <iostream>
#include <vector>

using namespace std;

int visit[101];
int graph[101][101];
int n;

void solve(){
    for (int k=0; k<n; k++) {
		for(int i=0; i<n; i++){
	        for(int j=0; j<n; j++){
				if (graph[i][k] && graph[k][j]) {
					graph[i][j] = 1; 
				}
			}
		}
	} 
	for(int i=0; i<n; i++){
	    for(int j=0;j<n;j++){
	        cout<<graph[i][j]<<" ";
	    }
	    cout<<"\n";
	}
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>graph[i][j];
        }
    }
    solve();
    return 0;
}