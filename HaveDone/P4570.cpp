#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<pair<ll,int>>a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end(),[&](pair<ll,int> &x,pair<ll,int>&y)->bool{
        return x.second > y.second;
    });
    ll ans = 0;
    vector<ll>basis(65);
    for(int i = 0;i < n;i++){
        auto [x,y] = a[i];
        for(int j = 60;j >= 0;j--){
            if((x>>j)&1){
                if(!basis[j]){
                    ans += y;
                    basis[j] = x;
                    break;
                }else{
                    x ^= basis[j];
                }
            }
        }
    }
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}