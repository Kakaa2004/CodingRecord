#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5;
int n,m;
int head[N];
struct Edge{
    int to;
    int next;
}edge[N<<1];
int cnt;
void init(){
    cnt = 0;
    for(int i = 0;i < N;i++){
        head[i] = -1;
    }
}
void addEdge(int u,int v){
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void solve(){
    init();
    vector<int>indegree(n+1);
    for(int i = 0;i < m;i++){
        int u,v;cin >> u >> v;
        indegree[v]++;
        addEdge(u,v);
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 1;i <= n;i++) if(!indegree[i]) q.push(i);
    while(q.size()){
        int p = q.top();q.pop();
        cout<<p<<" ";
        for(int i = head[p];i!=-1;i = edge[i].next){
            int v = edge[i].to;
            indegree[v]--;
            if(!indegree[v]) q.push(v);
        }
    }
    cout<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;
    while(cin >> n >> m) solve();
    return 0;
}