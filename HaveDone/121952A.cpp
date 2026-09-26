#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const ll inf = 1e18;
struct Edge{
    int next;
    int to;
}edge[N*2];
struct node{
    int p;
    int d;
    int tag;
};
int head[N];
int n,cnt;
bool vis[N];
int dist[N];
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
        vis[i] = false;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}


void bfs1(int a){
    queue<node>q;
    q.push({a,0,0});
    while(q.size()){
        auto [p,d,tag] = q.front();q.pop();
        vis[p] = true;
        dist[p] = d;
        for(int i = head[p];i!=-1;i = edge[i].next){
            int v = edge[i].to;
            if(!vis[v]){
                q.push({v,d+1,tag});
            }
        }
    }
}
void bfs2(int a,int b){
    queue<node>q;
    q.push({b,0,0});
    while(q.size()){
        auto [p,d,tag] = q.front();q.pop();
        //cout<<d<<" ";
        vis[p] = true;
        int cnt = 0;
        for(int i = head[p];i!=-1;i = edge[i].next){
            int v = edge[i].to;
            cnt++;
            if(!vis[v]){
                q.push({v,d+1-tag,tag!=1});

            }
        }
        if(cnt==1 && ((tag && dist[p]<d)||(!tag&&dist[p]<=d))){
            //cout<<p<<" ";
            cout<<"red\n";
            return ;
        }
    }
    cout<<"purple\n";
    return;
}
void solve(){
    init();
    cin >> n;
    int a,b;cin >> a >> b;
    for(int i = 0;i < n-1;i++){
        int u,v;cin >> u >> v;
        addEdge(u,v);
        addEdge(v,u);
    }
    bfs1(a);
    for(int i = 1;i <= n;i++) vis[i] =false;
    bfs2(a,b);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    //freopen("input.in","r",stdin);
   // freopen("output.out","w",stdout);
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}