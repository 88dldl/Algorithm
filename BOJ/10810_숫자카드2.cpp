#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL); ios::sync_with_stdio(false);
    int n, m, tmp;
    vector <int> number;
    //ют╥б
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        number.push_back(tmp);
    }
    sort(number.begin(), number.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        cout << upper_bound(number.begin(), number.end(), tmp) - lower_bound(number.begin(), number.end(), tmp) << " ";
    }

    return 0;
}