#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int64;

int N, M;
int64 K, B;
vector< pair<int64,int64> > segs;

bool possible(int64 T) {
    int64 rad = (T + B - 1) / 2;

    vector< pair<int64,int> > events;
    events.reserve(2 * N);

    for (int i = 0; i < N; i++) {
        int64 a = segs[i].first;
        int64 b = segs[i].second;

        int64 L = a - rad;
        int64 R = b + rad;

        if (L < 0) L = 0;
        if (R > K - 1) R = K - 1;

        if (L <= R) {
            events.push_back(make_pair(L, +1));
            events.push_back(make_pair(R + 1, -1));
        }
    }

    if (events.empty()) return false;

    sort(events.begin(), events.end());

    int64 cur = 0;
    size_t i = 0;

    while (i < events.size()) {
        int64 x = events[i].first;
        while (i < events.size() && events[i].first == x) {
            cur += events[i].second;
            i++;
        }
        if (cur >= M) return true;
    }

    return false;
}

int main() {
    cin >> N >> M >> K >> B;
    segs.resize(N);

    for (int i = 0; i < N; i++) {
        int64 H, W;
        cin >> H >> W;
        if (H <= W) segs[i] = make_pair(H, W);
        else segs[i] = make_pair(W, H);
    }

    int64 lo = 0;
    int64 hi = (1LL << 61);

    while (lo < hi) {
        int64 mid = lo + (hi - lo) / 2;
        if (possible(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
    return 0;
}

