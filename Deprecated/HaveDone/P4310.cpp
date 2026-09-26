#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int k; cin >> k;
    vector<int>a(k);
    for(int i = 0;i < k;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end(),[&](int x,int y)->bool{
        return x>y;
    });
    vector<int>basis(31);
    auto p = [&](int x)->bool{
        for(int i = 30;i >= 0;i--){
            if(((x>>i)&1) == 0) continue;
            if(!basis[i]){
                basis[i] = x;
                return true;
            }else{
                x^=basis[i];
            }
        }
        return false;
    };
    ll ans = 0;
    for(int i = 0;i < k;i++){
        if(!p(a[i])){
            ans+=a[i];
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