#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <random>
using namespace std;
typedef long long ll;
const int N = 3e5+5;
struct FHQ{
    int ls,rs,key,val,sz;
    bool inv;
}fhq[N];
int root,cnt,T1,T2,T3;
int n,m;
mt19937 rnd(114514);
int init(int x){
    fhq[++cnt] = {0,0,x,(int)rnd(),1,false};
    return cnt;
}
void up(int x){
    fhq[x].sz = fhq[fhq[x].ls].sz + fhq[fhq[x].rs].sz + 1;
}
void down(int x){
    if(fhq[x].inv){
        int tmp = fhq[x].ls;
        fhq[x].ls = fhq[x].rs;
        fhq[x].rs = tmp;
        fhq[fhq[x].ls].inv = !fhq[fhq[x].ls].inv;
        fhq[fhq[x].rs].inv = !fhq[fhq[x].rs].inv;
        fhq[x].inv = false;
    }
}
void split(int u,int v,int &x,int &y){
    if(!u){
        x = y = 0;
        return;
    }
    down(u);
    if(fhq[fhq[u].ls].sz + 1 > v){
        y = u;
        split(fhq[u].ls,v,x,fhq[u].ls);
    }else{
        x = u;
        split(fhq[u].rs,v - fhq[fhq[u].ls].sz - 1,fhq[u].rs,y);
    }
    up(u);
}
int merge(int x,int y){
    if(!x || !y){
        return x+y;
    }
    if(fhq[x].val > fhq[y].val){
        down(x);
        fhq[x].rs = merge(fhq[x].rs,y);
        up(x);
        return x;
    }else{
        down(y);
        fhq[y].ls = merge(x,fhq[y].ls);
        up(y);
        return y;
    }
}
void cut(int l,int r,int x){
    split(root,r,T1,T2);
    split(T1,l-1,T1,T3);
    if(fhq[T1].sz >= x){
        int tmp;
        split(T1,x,T1,tmp);
        root = merge(merge(merge(T1,T3),tmp),T2);
    }else{
        
        int tmp;
        split(T2,x-fhq[T1].sz,tmp,T2);
        root = merge(merge(merge(T1,tmp),T3),T2);
    }
}
void flip(int l,int r){
    split(root,r,T1,T2);
    split(T1,l-1,T1,T3);
    fhq[T3].inv = !fhq[T3].inv;
    root = merge(merge(T1,T3),T2);
}
void inorder(int u){
    if(u){
        down(u);
        inorder(fhq[u].ls);
        printf("%d ",fhq[u].key);
        inorder(fhq[u].rs);
    }
}
void solve(){
    cnt = 0;
    root = 0;
    for(int i = 1;i <= n;i++){
        root = merge(root,init(i));
    }
    for(int i = 1;i <= m;i++){
        string s;cin >> s;
        if(s=="CUT"){
            int l,r,x;cin >> l >> r >> x;
            cut(l,r,x);
        }else{
            int l,r;cin >> l >> r;
            flip(l,r);
        }
    }
    inorder(root);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1;
    cin >> n >> m;
    while(n!=-1 && m!=-1){
        solve();
        cin >> n >> m;
    }
    return 0;
}