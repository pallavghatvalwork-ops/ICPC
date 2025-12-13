#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int g, c, l;
    cin >> g >> c >> l;

    int mx = max(g, max(c, l));
    int mn = min(g, min(c, l));

    if (mx - mn >= 10) {
        cout << "check again";
    } else {
        int median = g + c + l - mx - mn;
        cout << "final " << median;
    }

    return 0;
}

