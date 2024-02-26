#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,d,root,leafsum=0;
vector<int> tree[50];
queue<int> q;
bool check[50];

void solve(int curnode)
{
    if(check[curnode]) return;
    check[curnode]=true;
    if(tree[curnode].size()==0 || (tree[curnode].size()==1 && tree[curnode][0]==d)){
        leafsum++;
    }
    for(int i=0;i<tree[curnode].size();i++){
        if(tree[curnode][i]!=d) solve(tree[curnode][i]);
    }
}

int main()
{
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        if(tmp==-1) root = i;
        else    tree[tmp].push_back(i); 
    }
    cin>>d;
    if(d==root) cout<<0;
    else {
        solve(root);
        cout<<leafsum;
    }
    return 0;
}