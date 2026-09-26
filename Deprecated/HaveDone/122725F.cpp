#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const ll inf = 1e18;
int fa[N];
ll dist[N];
void init(){
    for(int i = 0;i < N;i++){
        dist[i] = 0;
        fa[i] = i;
    }
}
int get(int x){
    if(fa[x] == x){
        return x;
    }else{
        int fx = get(fa[x]);
        dist[x] += dist[fa[x]];
        return fa[x] = fx;
    }
}
void merge(int x,int y,ll w){
    int fx = get(x);
    int fy = get(y);
    if(fx != fy){
        cout<<"OK\n";
        dist[fx] = w - dist[x];
        fa[fx] = y;
    }else{
        if(dist[x] - dist[y] != w){
            cout<<"CONTRADICTION\n";
        }else{
            cout<<"OK\n";
        }
    }
}
void solve(){
    int n,q;cin >> n >> q;
    init();
    for(int i = 0;i < q;i++){
        int op;cin >> op;
        if(op == 1){
            int u,v;
            ll k;
            cin >> u >> v >> k;
            merge(u,v,k);
        }else if(op == 2){
            int u;
            ll k;
            cin >> u >> k;
            merge(u,0,k);
        }else{
            int u,v;cin >> u >> v;
            if(get(u)==get(v)){
                cout<<dist[u] - dist[v]<<"\n";
            }else{
                cout<<"UNKNOWN\n";
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}