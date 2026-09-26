#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+5;
const int inf = 1e9;
int Max[MAXN<<2],Min[MAXN<<2];
int a[MAXN];
int ls(int p){return 2*p;}
int rs(int p){return 2*p+1;}
void up(int p){
    Max[p] = min(Max[ls(p)],Max[rs(p)]);
    Min[p] = min(Min[ls(p)],Min[rs(p)]);
}
void build(int p,int l,int r){
    if(l==r){
        Max[p] = Min[p] = a[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    up(p);
}
int query1(int L,int R,int p,int l,int r){
    if(L<=l&&r<=R){
        return Max[p];
    }
    int ans = -inf;
    int mid = (l+r)>>1;
    if(L<=mid) ans = min(ans,query1(L,R,ls(p),l,mid));
    if(R>mid) ans = min(ans,query1(L,R,rs(p),mid+1,r));
    return ans;
}
int query2(int L,int R,int p,int l,int r){
    if(L<=l&&r<=R){
        return Min[p];
    }
    int ans = inf;
    int mid = (l+r)>>1;
    if(L<=mid) ans = min(ans,query2(L,R,ls(p),l,mid));
    if(R>mid) ans = min(ans,query2(L,R,rs(p),mid+1,r));
    return ans;
}
void solve(){
    int n,q;cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    cout<<"\n";
    for(int i = 0,l,r;i < q;i++){
        cin >> l >> r;
        cout<<query1(l,r,1,1,n)-query2(l,r,1,1,n)<<"\n";
    }

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}