#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    char ch = getchar();
    int sum = 0;
    int f = 1;
    while(!isdigit(ch)){
        if(ch=='-') f = -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        sum = sum*10 + ch-'0';
        ch = getchar();
    }
    return sum*f;
}
void solve(){
    int n,m;n = read(),m = read();
    vector<int>a(n+1);
    for(int i = 0;i < n;i++){
        int tmp = read();
        a[tmp] = 1;
    }
    for(int i = 0;i < m;i++){
        int x = read();
        int ans = 0;
        for(int j = x;j <= n;j+=x){
            if(a[j]) ans = __gcd(ans,j);
        }
        if(ans==x){
            cout<<"YES\n";
        }else cout<<"NO\n";
    }
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;t = read();
    while(t--) solve();
    return 0;
}