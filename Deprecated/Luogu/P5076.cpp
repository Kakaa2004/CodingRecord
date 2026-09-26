#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4+5;
struct FHQ{
    int ls,rs,key,val,siz;
}fhq[N];
int root,cnt,T1,T2,T3;
mt19937 rnd(114514);
int init(int x){
    fhq[++cnt] = {0,0,x,(int)rnd(),1};
    return cnt;
}
void up(int x){
    fhq[x].siz = fhq[fhq[x].ls].siz + fhq[fhq[x].rs].siz + 1;
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
    root = merge(merge(T1,init(x)),T2);
}
int rnk(int x){
    split(root,x-1,T1,T2);
    int tmp = fhq[T1].siz + 1;
    root = merge(T1,T2);
    return tmp;
}
int kth(int k){
    int u = root;
    while(u){
        int tmp = fhq[fhq[u].ls].siz + 1;
        if(tmp == k){
            break;
        }else if(tmp > k){
            u = fhq[u].ls;
        }else{
            k -= tmp;
            u = fhq[u].rs;
        }
    }
    return fhq[u].key;
}
int pre(int x){
    split(root,x-1,T1,T2);
    int u = T1;
    while(u && fhq[u].rs) u = fhq[u].rs;
    root = merge(T1,T2);
    return (u == 0? -2147483647:fhq[u].key);
}
int suc(int x){
    split(root,x,T1,T2);
    int u = T2;
    while(u && fhq[u].ls) u = fhq[u].ls;
    root = merge(T1,T2);
    return (u == 0? 2147483647:fhq[u].key);
}
void solve(){
    int q;cin >> q;
    for(int i = 1,op,x;i <= q;i++){
        cin >> op >> x;
        if(op == 1){
            cout<<rnk(x)<<"\n";
        }else if(op == 2){
            cout<<kth(x)<<"\n";
        }else if( op == 3){
            cout<<pre(x)<<"\n";
        }else if(op ==4){
            cout<<suc(x)<<"\n";
        }else{
            add(x);
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