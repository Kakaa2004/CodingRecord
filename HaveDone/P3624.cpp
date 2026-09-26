#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e4+5;
int mp[200];
ll dp[N][20][5];
void solve(){
    mp['A'] = 1;mp['C'] = 2;mp['G'] = 3;mp['T'] = 4;
    char M[5] = {' ','A','C','G','T'};
    ll m,k,r;cin >> m >> k >> r;
    string s;cin >> s;
    if(mp[s[m-1]]){
        dp[m-1][1][mp[s[m-1]]] = 1;
    }else{
        for(int i = 1;i <= 4;i++){
            dp[m-1][1][i] = 1;
        }
    }
    for(int i = m-2;i >= 0;i--){
        for(int j = 1;j <= 4;j++){
            if(!mp[s[i]] || mp[s[i]] == j){
                for(int x = 1;x<= k;x++){
                    for(int y = 1;y<=4;y++){
                        dp[i][x][j] += dp[i+1][x - (j > y)][y];
                    }
                }
            }
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 1;j <= k;j++){
            for(int x = 1;x <= 4;x++){
                dp[i][j][x] += dp[i][j-1][x];
            }
        }
    }
    int lst = 0;
    for(int i = 0;i < m;i++){
        if(mp[s[i]]){
            printf("%c",s[i]);
            k -= (lst > mp[s[i]]);
            lst = mp[s[i]];
        }else{
            int now = 1;
            while(now<=4 && r>dp[i][k - (lst > now)][now]){
                r -= dp[i][k - (lst > now)][now];
                now++;
            }
            k -= (lst > now);
            printf("%c",M[now]);
            lst = now;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t =  1; //cin >> t;
    while(t--) solve();
    return 0;
}