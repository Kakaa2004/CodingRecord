#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double inf = 1e18;
struct point{
    int x;
    int y;
}Point[105];
struct Edge{
    int to;
    int next;
    double w;
}edge[2005];
struct Node{
    int u;
    double dis;
    bool operator <(const Node& a)const{
        return dis > a.dis;
    }
};
int head[105];
int cnt;
int n,m;
void init(){
    cnt = 0;
    for(int i = 0;i < 105;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,double w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
double getDis(int x,int y){
    double a = Point[x].x-Point[y].x;
    double b = Point[x].y-Point[y].y;
    return sqrt(a*a + b*b);
}
void solve(){
    init();
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> Point[i].x >> Point[i].y;
    }
    cin >> m;
    for(int i = 1;i <= m;i++){
        int u,v;cin >> u >> v;
        double d = getDis(u,v);
        addEdge(u,v,d);
        addEdge(v,u,d);
    }
    int s,t;cin >> s >> t;
    vector<bool>done(n+1);
    vector<double>dis(n+1,inf);
    priority_queue<Node>q;
    q.push({s,0.0});
    dis[s] = 0.0;
    while(!q.empty()){
        auto [u,d] = q.top();q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            double w = edge[i].w;
            if(done[v]) continue;
            if(d + w < dis[v]){
                dis[v] = d + w;
                q.push({v,dis[v]});
            }
        }
    }
    printf("%.2lf\n",dis[t]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}