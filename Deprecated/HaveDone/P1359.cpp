#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 205;
void solve(){
    int n;cin >> n;
    int dp[N][N];
    memset(dp,0x3f,sizeof(dp));
    for(int i = 1;i < n;i++){
        for(int j = i+1;j <= n;j++){
            cin >> dp[i][j];
        }
    }
    for(int i = 1;i <= n;i++){
        dp[i][i] = 0;
    }
    for(int i = n-1;i > 0;i--){
        for(int j = i+1;j <= n;j++){
            for(int k = i;k < j;k++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    cout<<dp[1][n];
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}