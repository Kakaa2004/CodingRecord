#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int two[25];
unordered_map<int,int>mp;
void init(){
    two[0] = 1; mp[1] = 0;
    for(int i = 1;i <= 17;i++){
        two[i] = two[i-1]*2;
        mp[two[i]] = i;
    }
}
int lowbit(int x){
    return x&(-x);
}
void solve(){
    int n,k;cin >> n >> k;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<vector<int>>pre(n+1,vector<int>(17));
    for(int i = 1;i <= n;i++){
        int tmp = a[i];
        int low = lowbit(tmp);
        int sum = 0;
        for(int j = 1;j <= 16;j++){
            while(mp[low]<j){
                sum+=lowbit(tmp);
                tmp+=lowbit(tmp);
                low = lowbit(tmp);
            }
            if(tmp > 100000){
                pre[i][j] = inf;
            }else{
                pre[i][j] = sum;
            }
        }
    }
    vector<vector<int>>dp(n+1,vector<int>(k+1,inf));
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++){
        dp[i][0] = 0;
        for(int j = k;j >= 1;j--){
            dp[i][j] = dp[i-1][j];
            for(int t = 1;t <= min(j,16);t++){
                if(pre[i][t]==inf || dp[i-1][j-t]==inf) continue;
                dp[i][j] = min(dp[i][j],dp[i-1][j-t]+pre[i][t]);
            }
        }
    }
    cout<<(dp[n][k]==inf?-1:dp[n][k]);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    init();
    while(t--) solve();
    return 0;
}