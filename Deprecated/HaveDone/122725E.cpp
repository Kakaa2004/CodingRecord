#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;
const int MOD = 1e9+7;
int arr[N];
int n,m;
void init(){
    for(int i = 1;i < N;i++){
        arr[i] = i*(i-1)/2;
    }
}
void solve(){
    cin >> n >> m;
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i = 1;i <= n && arr[i]<= m;i++){
        dp[i][arr[i]] = 2;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 1;arr[k]<=j && k <= i;k++){
                dp[i][j] =(dp[i][j] + dp[i-k][j-arr[k]])%MOD;
            }
        }
    }
    cout<<dp[n][m]<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    init();
    int t = 1;  cin >> t;
    while(t--) solve();
    
    return 0;
}