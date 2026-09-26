#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n,w;
int arr[20];
int dp[20][(1<<20)];
void solve(){
    cin >> n >> w;
    for(int i = 0;i < n;i++) cin >> arr[i];
    memset(dp,0x3f,sizeof(dp));
    for(int i = 0;i < n;i++){
        dp[1][(1<<i)] = arr[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < (1<<n);j++){
            if(dp[i][j]!=inf){
                for(int k = 0;k < n;k++){
                    if(((1<<k)&j)==0){
                        if(arr[k]+dp[i][j]<=w) dp[i][j | (1<<k)] = min(dp[i][j | (1<<k)],dp[i][j]+arr[k]);
                        else dp[i+1][j| (1<<k)] = min(dp[i+1][j | (1<<k)],arr[k]);
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(dp[i][(1<<n)-1]!=inf){
            cout<<i<<"\n";
            return ;
        }
    }

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}