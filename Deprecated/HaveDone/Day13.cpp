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
        s = 10*s+ch-'0';
        ch = getchar();
    }
    return s*f;
}
struct line{
    int l,r;
    bool operator < (const line &a)const{
        return (l==a.l)?(r>=a.r):l<=a.l;
    }
};
void solve(){
    int n,m;n = read(),m = read();
    vector<line>a(m);
    for(int i = 0,l,r; i < m;i++){
        l = read(),r  = read();
        a[i] = {l,r};
    }
    sort(a.begin(),a.end());
    int ans = 0;
    int st = 1;
    int l = a[0].l,r = a[0].r;
    for(int i = 1;i < m;i++){
        if(a[i].l>=l&&a[i].r<=r) continue;
        else if(a[i].l>=l&&a[i].l<=r&&a[i].r>=r){
            r = a[i].r;
        }else if(a[i].l>r){
            ans = min(ans,l-st);
            st = r+1;
            l = a[i].l;
            r = a[i].r;
        }
    }
    if(st<=l){
        ans = min(ans,l-st);
        st = r + 1;
    }
    ans = min(ans,n-st+1);
    cout<<ans;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}