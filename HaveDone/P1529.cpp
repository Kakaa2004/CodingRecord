#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct Node{
    int u;
    int dis;
    bool operator <(const Node& a)const{
        return dis > a.dis;
    }
};
struct Edge{
    int to;
    int next;
    int w;
}edge[100000];
int head[2000];
int cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < 2000;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v,int w){
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void solve(){
    init();
    vector<int>ans;
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        string s1,s2;
        int u,v, w;cin >> s1 >> s2 >> w;
        u = s1[0];
        v = s2[0];
        if(u>='A'&&u<='Y'){
            ans.push_back(u);
        }
        if(v>='A'&&v<='Y'){
            ans.push_back(v);
        }
        addEdge(u,v,w);
        addEdge(v,u,w);
    }
    priority_queue<Node>q;
    vector<int>dis(1000,inf),done(1000);
    int tmp = 'Z';
    dis[tmp] = 0;
    q.push({tmp,dis[tmp]});
    while(!q.empty()){
        auto [u,d] = q.top();q.pop();
        if(done[u]) continue;
        done[u] = 1;
        for(int i = head[u];~i;i = edge[i].next){
            int v = edge[i].to;
            int w = edge[i].w;
            if(done[v]) continue;
            if(d + w < dis[v]){
                dis[v] = d + w;
                q.push({v,dis[v]});
            }
        }
    }
    int Max = inf;
    int ch;
    for(auto i:ans){
        if(dis[i] < Max){
            Max = dis[i];
            ch = i;
        }
    }
    printf("%c %d\n",ch,Max);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}