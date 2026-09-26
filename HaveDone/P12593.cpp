#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
const int N = 10;
struct Node{
    ll v,w;
};
int n,m;
vector<Node>g[N];
ll dfs(int x,int status){
    if(x>n) return 0;
    ll ans = inf;
    for(int i = 1;i <= n;i++){
        if(((status>>i)&1) == 0){
            ll sum = 0;
            ll cnt = 0;
            for(auto it:g[i]){
                ll v = it.v;
                if(((status>>v)&1) == 0){
                    cnt++;
                    sum += it.w;
                }
            }
            ans = min(ans,sum*cnt+dfs(x+1,(status|(1<<i))));
        }
    }
    return ans;
}
void solve(){
    cin >> n >> m;
    for(ll i = 0,u,v,w;i < m;i++){
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cout<<dfs(1,0)<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int  t = 1;
    while(t--) solve();
    return 0;
}