#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
struct Edge {
    int to;
    int next;
} edge[N];
int head[N];
int in[N]; // 记录入度
int cnt;
void init() {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        head[i] = -1;
        in[i] = 0;
    }
}
void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void dfs(int u, int op) {
    if (!u) {
        return;
    }
    int ls = 0, rs = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        if (!ls) {
            ls = edge[i].to;
        } else {
            rs = edge[i].to;
        }
    }
    if (!ls && !rs) { // 叶子节点
        cout << u << " ";
        return;
    }
    if (ls && rs) {
        if (ls > rs) {
            swap(ls, rs);
        }
    } else {
        ls = min(ls, rs);
        if (ls < u) {
            rs = ls;
            ls = 0;
        } else {
            rs = 0;
        }
    }
    if (op == 1) {
        cout << u << " ";
    }
    dfs(ls, op);
    if (op == 2) {
        cout << u << " ";
    }
    dfs(rs, op);
    if (op == 3) {
        cout << u << " ";
    }
}
void solve() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        in[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!in[i]) {
            dfs(i, 1);
            cout << "\n";
            dfs(i, 2);
            cout << "\n";
            dfs(i, 3);
            cout << "\n";
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("1.in", "r", stdin);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}