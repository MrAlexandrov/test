#include <bits/stdc++.h>
using namespace std;

void rev (string &s, int l, int r) {
    for (; l < r; ++l, --r)
        swap(s[l], s[r]);
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector <pair <int, int>> ans;
    int ptr = 0;
    int m = (n - 2 * (k - 1)) / 2;
    for (int i = 0; i < m; ++i) {
        if (s[i] == '(') continue;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == '(') break;
            if (s[j] == '(') {
                ans.push_back({i, j});
                rev(s, i, j);
                if (j - i > 2) {
                    ans.push_back({i + 1, j - 1});
                    rev(s, i + 1, j - 1);
                }
            }
        }
    }
    for (int i = 2 * m; i < n; i += 2) {
        if (s[i] == '(') continue;
        for (int j = m; j < 2 * m; ++j) {
            if (s[i] == '(') break;
            if (s[j] == '(') {
                if (i > j) swap(i, j);
                ans.push_back({i, j});
                rev(s, i, j);
                if (j - i > 2) {
                    ans.push_back({i + 1, j - 1});
                    rev(s, i + 1, j - 1);
                }
                break;
            }
        }
        for (int j = 2 * m + 1; j < n; j += 2) {
            if (s[i] == '(') break;
            if (s[j] == '(') {
                if (i > j) swap(i, j);
                ans.push_back({i, j});
                rev(s, i, j);
                if (j - i > 2) {
                    ans.push_back({i + 1, j - 1});
                    rev(s, i + 1, j - 1);
                }
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    ans.erase(ans.begin(), ans.end());
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

/**
1
8 2
()(())()

**/
