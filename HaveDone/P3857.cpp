#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 2008;
void solve(){
    int n,m;cin >> n >> m;
    vector<ll>a(60);
    for(int i = 1;i <= m;i++){
        string s;cin >> s;
        for(int j = 0;j < n;j++){
            if(s[j] == 'O'){
                a[i] |= (1l<<(n-j-1));
            }
        }
    }
    int cnt = 1;
    for(int i = n-1; i>=0;i--){
        for(int j = cnt;j <= m;j++){
            if((a[j]>>i)&1){
                swap(a[cnt],a[j]);
                break;
            }
        }
        if((a[cnt]>>i)&1){
            for(int j = 1;j <= m;j++){
                if(cnt != j && ((a[j]>>i)&1)){
                    a[j] ^= a[cnt];
                }
            }
            cnt++;
        }
    }
    cnt--;
    cout<<(1l<<cnt)%MOD;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}