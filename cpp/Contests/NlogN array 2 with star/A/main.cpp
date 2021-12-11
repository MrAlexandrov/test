#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x -= 2;
        swap(a[x], a[x + 1]);
    }
    for (int i : a) {
        cout << i << ' ';
    }
    return 0;
}

/**


**/
