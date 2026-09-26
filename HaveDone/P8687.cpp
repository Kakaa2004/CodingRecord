#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n,m,k;
int a[105];
void solve(){
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++){
        for(int j = 0,tmp;j < k;j++){
            cin >> tmp;
            tmp--;
            a[i] |= (1<<tmp);
        }
    }
    vector<int>dp((1<<m),inf);
    dp[0] = 0;
    for(int i = 0;i < (1<<m);i++){
        if(dp[i]==inf) continue;
        for(int j = 0;j < n;j++){
            dp[i|a[j]] = min(dp[i|a[j]],dp[i]+1);
        }
    }
    cout<<(dp[(1<<m)-1]==inf?-1:dp[(1<<m)-1])<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}