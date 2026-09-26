#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
const int M = 1e7+5;
int arr[N],sorted[N],root[N];
int val[M],ls[M],rs[M];
ll sum[M];
int cnt;
int build(int l,int r){
    int rt = ++cnt;
    sum[rt] = 0;
    if(l<r){
        int mid = (l+r)>>1;
        ls[rt] = build(l,mid);
        rs[rt] = build(mid+1,r);
    }
    return rt;
}
int insert(int x,int l,int r,int i){
    int rt = ++cnt;
    ls[rt] = ls[i];
    rs[rt] = rs[i];
    sum[rt] = sum[i]+1;
    if(l<r){
        int mid = (l+r)>>1;
        if(x<=mid){
            ls[rt] = insert(x,l,mid,ls[rt]);
        }else{
            rs[rt] = insert(x,mid+1,r,rs[rt]);
        }
    }
    return rt;
}
int query(ll x,int l,int r,int u,int v){
    if(l==r){
        return l;
    }
    ll lsum = sum[ls[v]] - sum[ls[u]];
    int mid = (l+r)>>1;
    if(lsum >= x){
        return query(x,l,mid,ls[u],ls[v]);
    }else{
        return query(x-lsum,mid+1,r,rs[u],rs[v]);
    }
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        sorted[i] = arr[i];
    }
    sort(sorted+1,sorted+n+1);
    int d = 0;
    sorted[0] = -1e9;
    for(int i = 1;i <= n;i++){
        if(sorted[i]!=sorted[i-1]){
            sorted[++d] = sorted[i];
        }
    }
    root[0] = build(1,d);
    auto p = [&](int x)->int{
        int l = 0,r = d+1;
        while(l+1!=r){
            int mid = (l+r)>>1;
            if(sorted[mid]<=x){
                l = mid;
            }else{
                r = mid;
            }
        }
        return l;
    };
    for(int i = 1;i <= n;i++){
        int x = p(arr[i]);
        root[i] = insert(x,1,d,root[i-1]);
    }
    for(int i = 1;i <= m;i++){
        int l,r,k;cin >> l >> r >> k;
        cout<<sorted[query(k,1,d,root[l-1],root[r])]<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    while(t--) solve();
    return 0;
}