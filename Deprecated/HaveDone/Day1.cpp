#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int N = 5e5+5;
ll arr[N];
void init(){
    arr[0] = 1;
    for(int i = 1;i < N;i++){
        arr[i] = (arr[i-1]*i)%MOD;
    }
}
ll fastPow(ll x,ll a){
    ll ans = 1;
    while(a){
        if(a&1){
            ans = (ans * x)%MOD;
        }
        x = (x*x)%MOD;
        a = (a >> 1);
    }
    return ans;
}
void solve(){
    int n,m; cin >> n >> m;
    ll ans = ((arr[m] * fastPow(arr[n],MOD-2))%MOD)*fastPow(arr[m-n],MOD-2)%MOD;
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; cin >> t;
    init();
    while(t--){
        solve();
    }
    return 0;
}