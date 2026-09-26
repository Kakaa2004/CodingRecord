#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -f;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        s = (s << 3) + (s << 1) + ch - 48;
        ch = getchar();
    }
    return s * f;
}
struct node {
    int h, a;
    bool operator<(const node &x) const {
        if (h == x.h) {
            return a < x.a;
        } else {
            return h > x.h;
        }
    }
};
void solve() {
    int n = read(), h = read(), a = read();
    vector<node> tmp(n), v;
    for (int i = 0; i < n; i++) {
        tmp[i].h = read();
    }
    for (int i = 0; i < n; i++) {
        tmp[i].a = read();
    }
    for (int i = 0; i < n; i++) {
        if (tmp[i].h < h && tmp[i].a < a) {
            v.push_back(tmp[i]);
        }
    }
    sort(v.begin(), v.end());
    n = v.size();
    vector<int> dp(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (v[i].h < v[j].h && v[i].a < v[j].a) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";
}
int main() {
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}