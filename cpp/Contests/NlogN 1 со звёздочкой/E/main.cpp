#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    /*string s = "GCV";
    for (int i = 0; i < 2 * k; ++i) {
        if (i % 2 == 1) {
            swap(s[0], s[1]);
        } else {
            swap(s[1], s[2]);
        }
    }
    cout << s << endl;
    */

    if (k % 3 == 0) {
        cout << "GCV" << endl;
    } else if (k % 3 == 1) {
        cout << "VGC" << endl;
    } else if (k % 3 == 2) {
        cout << "CVG" << endl;
    }

    return 0;
}

/**
0. GCV

1. GVC
   VGC

2. VCG
   CVG

3. CGV
   GCV

**/
