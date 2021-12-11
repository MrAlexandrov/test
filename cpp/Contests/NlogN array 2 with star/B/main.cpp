#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a[3];
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        --t;
        a[t].push_back(i);
    }
    int k = min({(int)a[0].size(), (int)a[1].size(), (int)a[2].size()});
    cout << k << '\n';
    for (int j = 0; j < k; ++j) {
        for (int i = 0; i < 3; ++i) {
            cout << a[i][j] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/**


**/
