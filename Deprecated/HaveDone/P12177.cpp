#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void print(__int128 ans){
    if(!ans) return ;
    print(ans/10);
    putchar(ans%10+'0');
}
void solve(){
    ll n;cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<vector<ll>>rec(n+1,vector<ll>(21));
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= 20;j++){
            rec[i][j] = ((a[i]>>j)&1);
        }
    }
    vector<vector<ll>>sum(21,vector<ll>(2));
    for(int i = 0;i <= 20;i++){
        for(ll j = 2;j <= n;j++){
            sum[i][0] += 1l*rec[j][i];
            sum[i][1] += 1l*rec[j][i]*(j-1);
        }
    }
    __int128 ans = 0;
    for(int i = 0;i <=20;i++){
        for(ll j = 1;j < n;j++){
            if(!rec[j][i]){
                ans += 1l*sum[i][1]*(1l<<i);
            }else{
                ans += 1l*(1l*(n-j)*(n-j+1l)/2l - sum[i][1])*(1l<<i);
            }
            sum[i][1] -= sum[i][0];
            sum[i][0] -= rec[j+1][i];
        }
    }
    print(ans);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}