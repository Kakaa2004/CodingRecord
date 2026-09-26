#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
struct Edge {
    int to, next;
} edge[N << 1];
int head[N];
int cnt;
void init() {
    cnt = 0;
    for (int i = 0; i < N; i++) {
        head[i] = -1;
    }
}
void addEdge(int u, int v) {
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
int dfs(int u, int f) {
    int ans = 0;
    int cnt = 0;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (v != f) {
            cnt++;
            ans += dfs(v, u);
        }
    }
    if (f == -1 && cnt == 1) {
        ans++;
    }
    return (cnt ? ans : 1);
}
void solve() {
    init();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    cout << (dfs(1, -1) + 1) / 2 << "\n";
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