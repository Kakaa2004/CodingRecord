#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
int n;
int a[25][25];
int dp[20][N];
void solve(){
    if(n==0){
        cout<<"0\n";
        return ;
    }
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++) cin >> a[i][j];
    }
    int m = 0;
    vector<int> hash(N);
    for(int i = 0;i < (1<<n);i++){
        if(!(i&(i<<1))) hash[m++] = i;
    }
    auto p = [&](int r,int c)->int{
        int sum = 0;
        for(int i = 0;i < n;i++){
            if((c>>i)&1) sum += a[r][i];
        }
        return sum;
    };
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            int s = hash[j];
            int sum = p(i,s);
            if(!i) dp[i][j] = sum;
            else{
                for(int k = 0;k < m;k++){
                    if(!(hash[k]&s)){
                        int sum1 = p(i-1,hash[k]);
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+sum);
                    }
                }
            } 
        }
    }
    int ans = 0;
    for(int i = 0;i < m;i++){
        ans = min(ans,dp[n-1][i]);
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    //int t = 1; cin >> t;
    while(cin >> n) solve();
    return 0;
}