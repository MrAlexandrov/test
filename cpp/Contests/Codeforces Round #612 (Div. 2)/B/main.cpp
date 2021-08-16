#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <ll, ll> pll;

vector <char> ex = {'E', 'S', 'T'};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            string t = a[i];
            string x = a[i], y = a[j];
            for (int q = 0; q < k; ++q) {
                if (x[q] == y[q]) {
                    t[q] = x[q];
                } else {
                    for (int w = 0; w < 3; ++w) {
                        if (ex[w] != x[q] && ex[w] != y[q]) {
                            t[q] = ex[w];
                            break;
                        }
                    }
                }
            }
            if (binary_search(a.begin() + j + 1, a.end(), t)) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

/**


**/
