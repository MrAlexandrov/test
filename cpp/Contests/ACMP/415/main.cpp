#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;

void prefix(string &s, vector <ll> &pi) {
    ll n = s.size();
    pi.resize(n);
    pi[0] = 0;
    for (ll i = 1; i < n; ++i) {
        ll j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            ++j;
        }
        pi[i] = j;
    }
}

bool comp(string &a, string &b) {
    if (a.size() != b.size()) {
        return (a < b);
    }
    for (ll i = 0; i < a.size(); ++i) {
        if (a[i] < b[i]) {
            return true;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ///freopen("input.in", "r", stdin);
    ///freopen("output.out", "w", stdout);
    cin >> s >> t;
    cout << ('a' < 'A') << endl;
    return 0;

    string a = s + '#' + t;
    string b = t + '#' + s;
    for (ll i = 0; i < a.size(); ++i) {
        if ('A' <= a[i] && a[i] <= 'Z') {
            a[i] -= (int)('A' - 'a');
        }
        if ('A' <= b[i] && b[i] <= 'Z') {
            b[i] -= (int)('A' - 'a');
        }
    }
    vector <ll> aa, bb;
    prefix(a, aa);
    prefix(b, bb);
    /*
    cout << a << endl;
    for (ll i : aa) {
        cout << i << ' ';
    }
    cout << endl << b << endl;
    for (ll i : bb) {
        cout << i << ' ';
    }
    cout << endl;
    */

    string ansa = t;
    if ('a' <= ansa[ansa.size() - aa.back()] && ansa[ansa.size() - aa.back()] <= 'z') {
        ansa[ansa.size() - aa.back()] += (int)('A' - 'a');
    }
    ansa += s.substr(aa.back());

    string ansb = s;
    if ('a' <= ansb[ansb.size() - bb.back()] && ansb[ansb.size() - bb.back()] <= 'z') {
        ansb[ansb.size() - bb.back()] += (int)('A' - 'a');
    }
    ansb += t.substr(bb.back());

    cout << (ansa < ansb ? ansa : ansb) << '\n';
    return 0;
}

/**


**/
