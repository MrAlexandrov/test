#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (c) {
        if (a) {
            if (a == d) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            cout << 0 << endl;
        }
    } else {
        if (a == d) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}

/**


**/
