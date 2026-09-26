/*
    树状数组
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
const int MOD = 1e9+7;
ll n,m;
ll arr[N];
ll treeE[N];
ll treeD[N];
ll lowbit(ll x){
    return x&(-x);
}
void add(ll x,ll y,ll z){
    while(x<=n){
        treeE[x] = (treeE[x] +y)%MOD;
        treeD[x] = (treeD[x] +z)%MOD;
        x += lowbit(x);
    }
}
ll fpow(ll a,ll x){
    ll s = 1;
    while(x){
        if(x&1) s = (s*a)%MOD;
        x>>=1;
        
        a = (a*a)%MOD;
    }
    return s;
}
ll query1(ll x){
    ll ans = 0;
    while(x){
        ans = (ans+ treeE[x])%MOD;
        x -= lowbit(x);
    }
    return ans;
}
ll query2(ll x){
    ll ans = 0;
    while(x){
        ans = (ans+ treeD[x])%MOD;
        x -= lowbit(x);
    }
    return ans;
}
void solve(){
    cin >> n  >> m;
    for(int i = 1;i <= n;i++) cin >> arr[i],add(i,arr[i],arr[i]*arr[i]%MOD);
    for(int i = 1;i <= m;i++){
        ll op,x,y;cin >> op;
        if(op==1){
            cin >> x >> y;
            ll tmp = (query1(x)-query1(x-1))%MOD;
            ll t = y*y%MOD - tmp*tmp%MOD;
            add(x,(y-tmp)%MOD,(t+MOD)%MOD);
        }else{
            cin >> x >> y;
            ll inv = fpow(y-x+1,MOD-2);
            ll e = ((query1(y)-query1(x-1))*inv)%MOD;
            ll d = query2(y)-query2(x-1);
            ll ans = d*inv%MOD-e*e%MOD;
            ans = (ans%MOD + MOD)%MOD;
            cout<<ans<<"\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}