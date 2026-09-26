#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    int n;cin >> n;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++){
        cin >>a[i];
    }
    vector<int>ls(n+1),rs(n+1),st(n+1);
    int top = 0;
    int pos;
    for(int i = 1;i <= n;i++){
        pos = top;
        while(pos>0 && a[st[pos]] > a[i]){
            pos--;
        }
        if(pos > 0){
            rs[st[pos]] = i;
        }
        if(pos < top){
            ls[i] = st[pos+1];
        }
        st[++pos] = i;
        top = pos;
    }
    ll ans1 = 0,ans2 = 0;
    for(ll i = 1;i <= n;i++){
        ans1 ^= i * (ls[i] + 1l);
        ans2 ^= i * (rs[i] + 1l);
    }
    cout<<ans1<<" "<<ans2;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}