#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int MOD = 10007;
const int N = 1e4+5;
ll dp[N];
ll inv[N];
ll fpow(ll a,ll x){
	ll ans = 1;
	while(x){
		if(x&1){
			ans = (ans*a)%MOD;
		}
		a = (a*a)%MOD;
		x>>=1;
	}
	return ans;
}
void init(){
	dp[0] = 1;
	inv[0] = 1;
	for(int i = 1;i < N;i++){
		dp[i] = (dp[i-1]*i)%MOD;
		inv[i] = fpow(dp[i],MOD-2);
	}
}
void solve(){
	ll n,m;cin >> n >> m;
	ll res = 1;
	ll cnt = n;
	for(int i = 1;i <= m;i++){
		ll tmp;cin >> tmp;
		res = (res*dp[cnt]*inv[tmp]*inv[cnt-tmp])%MOD;
		cnt -= tmp;
	}
	cout<<res;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t = 1;
	init();
	while(t--){
		solve();
	}
	return 0;
}
