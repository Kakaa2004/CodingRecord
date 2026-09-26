#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5;
int f[N], sz[N], rec[N];
struct node {
    int a, b, r;
};
inline int read() {
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (f == '-')
            f = -f;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = (s << 3) + (s << 1) + (ch - 48);
        ch = getchar();
    }
    return s * f;
}
int find(int x) {
    if (x == f[x]) {
        return x;
    }
    int fx = find(f[x]);
    if (sz[x]) {
        sz[x] = sz[f[x]];
    } else {
        sz[x] = !sz[f[x]];
    }
    return f[x] = fx;
}
void solve() {
    int n = read();
    vector<node> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        a[i].a = read(), a[i].b = read(), a[i].r = read();
        rec[++cnt] = a[i].a;
        rec[++cnt] = a[i].b;
    }
    sort(rec + 1, rec + cnt + 1);
    int len = 0;
    for (int i = 1; i <= cnt; i++) {
        if (rec[i] != rec[len]) {
            rec[++len] = rec[i];
        }
    }
    auto p = [&](int x) -> int {
        int l = 0, r = len + 1;
        while (l + 1 != r) {
            int mid = (l + r) >> 1;
            if (rec[mid] >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r + 1;
    };
    for (int i = 0; i < len + 100; i++) {
        f[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        int x = p(a[i].a), y = p(a[i].b);
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            f[fx] = fy;
            sz[fx] = a[i].r;
        } else {
            if (!(sz[fx] ^ sz[fy]) != a[i].r) {
                cout << "NO\n";
                return;
            }
        }
    }
    printf("YES\n");
}
int main() {
    // freopen("1.in", "r", stdin);
    int t = read();
    while (t--) {
        solve();
    }
    return 0;
}