#include <bits/stdc++.h>
using namespace std;

int solve() {
    string t, s;
    cin >> t >> s;
    int a[26];
    for (int i = 0; i < 26; ++i) {
        a[t[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        ans += abs(a[s[i - 1] - 'a'] - a[s[i] - 'a']);
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
