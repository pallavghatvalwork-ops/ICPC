#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int l, a, b;
        cin >> l >> a >> b;

        int g = __gcd(l, b);
        int steps = l / g;

        int cur = a;
        int ans = a;

        for (int i = 0; i < steps; i++) {
            cur = (cur + b) % l;
            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }
    return 0;
}
