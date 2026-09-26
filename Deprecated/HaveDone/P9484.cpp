#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int s = 0,f = 1;
    char ch = getchar();
    while(!isdigit(ch)){
        if(ch=='-') f = -f;
        ch = getchar();
    }
    while(isdigit(ch)){
        s = s*10 + ch-'0';
        ch = getchar();
    }
    return s*f;
}
void solve(){
    int n,q; n = read(),q = read();
    for(int i = 0;i < q;i++){
        int x = read(),y = read();
        if(x>y) swap(x,y);
        int e = __gcd(x,y);
        printf("%d\n",x+y-2*e);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; t = read();
    while(t--) solve();
}