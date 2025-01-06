#include <iostream>
#include <stack>
#include <string>

using namespace std;

string n;
stack<char> s;
    
void solve(){
    for(int i=0;i<n.length();i++){
        if(n[i] >= 'A' && n[i] <= 'Z'){
            cout << n[i];
            continue;
        }
        if(n[i]=='('){
            s.push(n[i]);
        }
        else if(n[i]==')'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.pop();
        }
        else if(n[i] == '*' || n[i] == '/'){
            while(!s.empty() && (s.top() == '*' || s.top() == '/')){
                cout << s.top();
                s.pop();
            }
            s.push(n[i]);
        }
        else if(n[i] == '+' || n[i] == '-'){
            while(!s.empty() && s.top() != '('){
                cout << s.top();
                s.pop();
            }
            s.push(n[i]);     
        }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int main()
{
    cin>>n;
    
    solve();
    
    return 0;
}