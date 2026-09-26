#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
const int N = 1e6+5;
struct FHQ{
    int ls,rs,key,val,sz;
}fhq[N];
int f[N];
mt19937 rnd(114514);
int root,cnt,T1,T2,T3;
void init(){
    f[0] = 1;
    for(int i = 1;i < N;i++){
        f[i] = 1l * f[i-1] * i %MOD;
    }
}
int create(int x){
    fhq[++cnt] = {0,0,x,(int)rnd(),1};
    return cnt;
}
void up(int x){
    fhq[x].sz = fhq[fhq[x].ls].sz + fhq[fhq[x].rs].sz + 1;
}
void split(int u,int v,int &x,int &y){
    if(!u){
        x = y = 0;
        return ;
    }
    if(fhq[u].key > v){
        y = u;
        split(fhq[u].ls,v,x,fhq[u].ls);
    }else{
        x = u;
        split(fhq[u].rs,v,fhq[u].rs,y);
    }
    up(u);
}
int merge(int x,int y){
    if(!x || !y){
        return x+y;
    }
    if(fhq[x].val > fhq[y].val){
        fhq[x].rs = merge(fhq[x].rs,y);
        up(x);
        return x;
    }else{
        fhq[y].ls = merge(x,fhq[y].ls);
        up(y);
        return y;
    }
}
void add(int x){
    split(root,x,T1,T2);
    root = merge(merge(T1,create(x)),T2);
}
void remove(int x){
    split(root,x,T1,T2);
    split(T1,x-1,T1,T3);
    T3 = merge(fhq[T3].ls,fhq[T3].rs);
    root = merge(T1,T2);
}
int get(int x){
    split(root,x-1,T1,T2);
    int res = fhq[T1].sz;
    root = merge(T1,T2);
    return res;
}
void solve(){
    int res = 0;
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        add(i);
    }
    for(int i = 1;i <= n;i++){
        int tmp;cin >> tmp;
        res = (res + 1l * get(tmp) * f[n-i]) %MOD;
        remove(tmp);
    }
    cout<<(res+1)%MOD;
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    init();
    while(t--) solve();
    return 0;
}