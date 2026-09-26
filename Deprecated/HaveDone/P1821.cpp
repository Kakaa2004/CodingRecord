#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
struct Edge{
    int to;
    int w;
    int next;
}edge1[100005],edge2[100005];
struct Node{
    int x;
    int d;
    bool operator <(const Node& a)const{
        return d > a.d;
    }
};
int head1[1005];
int head2[1005];
int cnt1,cnt2;
void init(){
    cnt1 = cnt2 =  0;
    for(int i = 0;i < 1005;i++){
        head1[i] = head2[i] =  -1;
    }
}
void addEdge1(int u,int v,int w){
    edge1[cnt1].to = v;
    edge1[cnt1].w = w;
    edge1[cnt1].next = head1[u];
    head1[u] = cnt1++;
}
void addEdge2(int u,int v,int w){
    edge2[cnt2].to = v;
    edge2[cnt2].w = w;
    edge2[cnt2].next = head2[u];
    head2[u] = cnt2++;
}
void solve(){
    init();
    int n,m,x; cin >> n >> m >> x;
    for(int i = 1;i <= m;i++){
        int u,v,w;cin >> u >> v >> w;
        addEdge1(u,v,w);
        addEdge2(v,u,w);
    }
    vector<bool>done1(n+1);
    vector<int>dis1(n+1,inf);
    priority_queue<Node>q1;
    q1.push({x,0});
    dis1[x] = 0;
    while(!q1.empty()){
        auto [u,d] = q1.top();q1.pop();
        if(done1[u]) continue;
        done1[u] = true;
        for(int i = head1[u];~i;i = edge1[i].next){
            int v = edge1[i].to;
            int w = edge1[i].w;
            if(done1[v]) continue;
            if(d + w < dis1[v]){
                dis1[v] = d + w;
                q1.push({v,dis1[v]});
            }
        }
    }
    vector<bool>done2(n+1);
    vector<int>dis2(n+1,inf);
    priority_queue<Node>q2;
    q2.push({x,0});
    dis2[x] = 0;
    while(!q2.empty()){
        auto [u,d] = q2.top();q2.pop();
        if(done2[u]) continue;
        done2[u] = true;
        for(int i = head2[u];~i;i = edge2[i].next){
            int v = edge2[i].to;
            int w = edge2[i].w;
            if(done2[v]) continue;
            if(d + w < dis2[v]){
                dis2[v] = d + w;
                q2.push({v,dis2[v]});
            }
        }
    }
    int ans = -inf;
    for(int i = 1;i <= n;i++){
        if(i!=x && dis1[i] + dis2[i] < inf){
            ans = min(ans,dis1[i] + dis2[i]);
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}