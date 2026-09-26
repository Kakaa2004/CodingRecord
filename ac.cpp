#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int ddx[] = {1,1,-1,-1,2,2,-2,-2};
const int ddy[] = {2,-2,2,-2,1,-1,1,-1};

const int MAXNODE = 40010;
const int MAXEDGE = 40000 * 20;

struct Edge {
    int to, next, w;
} edge[MAXEDGE];

int head[MAXNODE], cur[MAXNODE], dep[MAXNODE], cnt;
int S, T;

void addEdge(int u, int v, int w) {
    edge[cnt] = {v, head[u], w};
    head[u] = cnt++;
    edge[cnt] = {u, head[v], 0};
    head[v] = cnt++;
}

bool bfs() {
    memset(dep, 0, sizeof dep);
    queue<int> q;
    q.push(S);
    dep[S] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].to;
            if (edge[i].w > 0 && !dep[v]) {
                dep[v] = dep[u] + 1;
                q.push(v);
                if (v == T) return true;
            }
        }
    }
    return false;
}

int dfs(int u, int flow) {
    if (u == T) return flow;
    int used = 0;
    for (int &i = cur[u]; ~i; i = edge[i].next) {
        int v = edge[i].to;
        if (edge[i].w > 0 && dep[v] == dep[u] + 1) {
            int f = dfs(v, min(flow - used, edge[i].w));
            if(f>0){
                edge[i].w -= f;
                edge[i^1].w += f;
                used += f;
                if(used == flow) break;
            }
        }
    }
    return used;
}

int dinic() {
    int mf = 0;
    while(bfs()){
        for(int i=0;i<=T;i++) cur[i]=head[i];
        while(int f=dfs(S,inf)) mf += f;
    }
    return mf;
}

inline int encode(int x, int y) {
    return (x-1)*200 + y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(head, -1, sizeof head);
    cnt = 0;
    int n,m;
    cin >> n >> m;
    S = 0;
    T = 40001;
    vector<bool> ban(T+1,false);
    for(int i=1;i<=m;i++){
        int x,y; cin >> x >> y;
        ban[encode(x,y)] = true;
    }
    int total = n*n - m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int id = encode(i,j);
            if(ban[id]) continue;
            if((i+j)%2 ==0){
                addEdge(S, id,1);
                for(int k=0;k<8;k++){
                    int nx = i+ddx[k];
                    int ny = j+ddy[k];
                    if(nx<1||nx>n||ny<1||ny>n) continue;
                    int nid = encode(nx,ny);
                    if(ban[nid]) continue;
                    addEdge(id, nid,1);
                }
            }else{
                addEdge(id, T, 1);
            }
        }
    }
    cout << total - dinic() << endl;
    return 0;
}
