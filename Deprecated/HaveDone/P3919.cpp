#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e7;
int arr[N],val[N],root[N],ls[N],rs[N];
int cnt = 0;
int build(int l,int r){
    int rt = ++cnt;
    if(l==r){
        val[rt] = arr[l];
    }else{
        int mid = (l+r)>>1;
        ls[rt] = build(l,mid);
        rs[rt] = build(mid+1,r);
    }
    return rt;
}
int update(int x,int v,int l,int r,int ver){
    int rt = ++cnt;
    ls[rt] = ls[ver];
    rs[rt] = rs[ver];
    if(l==r){
        val[rt] = v;
    }else{
        int mid = (l+r)>>1;
        if(x<=mid){
            ls[rt] = update(x,v,l,mid,ls[rt]);
        }else{
            rs[rt] = update(x,v,mid+1,r,rs[rt]);
        }
    }
    return rt;
}
int query(int x,int l,int r,int rt){
    if(l==r){
        return val[rt];
    }
    int mid = (l+r)>>1;
    if(x<=mid){
        return query(x,l,mid,ls[rt]);
    }else{
        return query(x,mid+1,r,rs[rt]);
    }
}
void solve(){
    int n,m;cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    root[0] = build(1,n);
    for(int i = 1;i <= m;i++){
        int version,op,x;cin >> version >> op >> x;
        if(op==1){
            int y;cin >> y;
            root[i] = update(x,y,1,n,root[version]);
        }else{
            root[i] = root[version];
            cout<<query(x,1,n,root[version])<<"\n";
        }
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