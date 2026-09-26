#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 1e6+5;
struct Edge{
    int to;
    int w;
    int next;
}edge[N];
int head[10005];
int dis[10005];
bool inq[10005];
int cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < 10005;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void spfa(){    
    for(int i = 1;i <= 10000;i++){
        dis[i] = inf;
        inq[i] = false;
    }
    queue<int>q;
    q.push(1);
    dis[1] = 0;inq[1] = true;
    while(!q.empty()){
        int u = q.front();q.pop();
        inq[u] = false;
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;
                if(!inq[v]){
                    q.push(v);
                    inq[v] = true;
                }
            }
        }
    }
}
void solve(){
    init();
    vector<int>t1(105);
    vector<int>t2(105);
    int p = 2;
    t1[1] = 1;
    int n;cin >> n;
    int k;
    for(int i = 1;i <= n;i++){
        cin >> k;
        for(int j = 1;j <= k;j++,p++){
            int u,w; cin >> u;
            while(u){
                cin >> w;
                addEdge(t1[u],p,w);
                cin >> u;
            }
            t2[j] = p;
        }
        for(int j = 1;j <= k;j++){
            t1[j] = t2[j];
        }
    }
    spfa();
    int ans = inf;
    for(int i = 1;i <= k;i++){
        ans =  min(ans,dis[t1[i]]);
    }
    cout<<ans;
}
int main(void){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; //cin >> n;
    while(t--) solve();
    return 0;
}