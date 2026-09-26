#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 rnd(114514);
const int N = 5e5 + 5;
struct FHQ {
    int ls, rs, val, key, siz, sum, lzy;
} fhq[N];
int cnt;
int T1, T2, T3;
int root;
int init(int x) {
    fhq[++cnt] = {0, 0, x, (int)rnd(), 1, x, 0};
    return cnt;
}
void up(int u) {
    fhq[u].siz = fhq[fhq[u].ls].siz + fhq[fhq[u].rs].siz + 1;
    fhq[u].sum = fhq[fhq[u].ls].sum + fhq[fhq[u].rs].sum + fhq[u].val;
}
void addLazy(int u) {
    fhq[u].lzy ^= 1;
    fhq[u].val ^= 1;
    fhq[u].sum = fhq[u].siz - fhq[u].sum;
}
void down(int u) {
    if (fhq[u].lzy) {
        addLazy(fhq[u].ls);
        addLazy(fhq[u].rs);
        fhq[u].lzy = 0;
    }
}
void split(int u, int k, int &x, int &y) {
    if (!u) {
        x = y = 0;
        return;
    }
    down(u);
    if (fhq[fhq[u].ls].siz + 1 > k) {
        y = u;
        split(fhq[u].ls, k, x, fhq[u].ls);
    } else {
        x = u;
        split(fhq[u].rs, k - fhq[fhq[u].ls].siz - 1, fhq[u].rs, y);
    }
    up(u);
}
int merge(int x, int y) {
    if (!x || !y) {
        return x + y;
    }
    if (fhq[x].key > fhq[y].key) {
        down(x);
        fhq[x].rs = merge(fhq[x].rs, y);
        up(x);
        return x;
    } else {
        down(y);
        fhq[y].ls = merge(x, fhq[y].ls);
        up(y);
        return y;
    }
}
void add(int x) { root = merge(root, init(x)); }
int query(int l, int r) {
    split(root, r, T1, T2);
    split(T1, l - 1, T1, T3);
    int ans = fhq[T3].sum;
    root = merge(merge(T1, T3), T2);
    return ans;
}
void change(int l, int r) {
    split(root, r, T1, T2);
    split(T1, l - 1, T1, T3);
    addLazy(T3);
    root = merge(merge(T1, T3), T2);
}
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        add(s[i] - '0');
    }
    for (int i = 1; i <= q; i++) {
        int op, l, r;
        cin >> op >> l >> r;
        if (op == 1) {
            change(l, r);
        } else {
            cout << query(l, r) << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}