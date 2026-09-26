/*
    使用Floyd算法求解
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int f(string s){
    char ch = s[0];
    if(ch>='a' && ch<='z'){
        return ch-'a'+1;
    }else{
        return ch-'A'+27;
    }
}
void solve(){
    int dp[500][500];
    memset(dp,0x3f,sizeof(dp));
    int n;cin >> n;
    for(int i = 1;i <= 100;i++){
        dp[i][i] = 0;
    }
    for(int i = 1;i <= n;i++){
        string s1,s2;
        int w;
        cin >> s1 >> s2 >> w;
        dp[f(s1)][f(s2)] = min(dp[f(s1)][f(s2)],w);
        dp[f(s2)][f(s1)] = min(dp[f(s2)][f(s1)],w);
    }
    for(int i = 1;i <= 52;i++){
        for(int j = 1;j <= 52;j++){
            for(int k = 1;k <= 52;k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    int ans = inf;
    int rec;
    for(int i = 27;i <= 51;i++){
        if(dp[i][52] < ans){
            ans = dp[i][52];
            rec = i+'A'-27;
        }
    }
    printf("%c %d",rec,ans);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}