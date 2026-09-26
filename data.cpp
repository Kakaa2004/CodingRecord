#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
mt19937 rnd(time(0));
int randomInt(int l,int r){
    uniform_int_distribution<int> dist(l,r);
    return dist(rnd);
}
void solve(){
    cout<<randomInt(1,50)<<" "<<randomInt(1,50);
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}