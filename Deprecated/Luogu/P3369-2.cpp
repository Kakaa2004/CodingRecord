#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
mt19937 rnd(114514);
struct FHQ{
    int ls,rs,key,sz,val;
}fhq[N];
int cnt = 0;
int head = 0;
int T1,T2,T3;
void up(int u){
    fhq[u].sz = fhq[fhq[u].ls].sz + fhq[fhq[u].rs].sz + 1;
}
int init(int u){
    fhq[++cnt] = {0,0,(int)rnd(),1,u};
    return cnt;
}
void split(int u,int v,int &x,int &y){
    if(!u){
        x = y = 0;
        return;
    }
    if(fhq[u].val > v){
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
    if(fhq[x].key > fhq[y].key){
        fhq[x].rs = merge(fhq[x].rs,y);
        up(x);
        return x;
    }else{
        fhq[y].ls = merge(x,fhq[y].ls);
        up(y);
        return y;
    }
}
void add(int num){
    split(head,num,T1,T2);
    head = merge(merge(T1,init(num)),T2);
}
void remove(int num){
    split(head,num,T1,T2);
    split(T1,num-1,T1,T3);
    T3 = merge(fhq[T3].ls,fhq[T3].rs);
    head = merge(merge(T1,T3),T2);
}
int rnk(int x){
    split(head,x-1,T1,T2);
    int res = fhq[T1].sz + 1;
    head = merge(T1,T2);
    return res;
} 
int kth(int x){
    int u = head;
    while(u){
        int tmp = fhq[fhq[u].ls].sz + 1;
        if(tmp == x){
            break;
        }else if(x < tmp){
            u = fhq[u].ls;
        }else{
            x -= tmp;
            u = fhq[u].rs;
        }
    }
    return fhq[u].val;
}
int pre(int u,int v){
    if(u==0){
        return INT_MIN;
    }
    if(fhq[u].val < v){
        int res = pre(fhq[u].rs,v);
        return (res == INT_MIN ? fhq[u].val : res);
    }else{
        return pre(fhq[u].ls,v);
    }
}
int nxt(int u,int v){
    if(u==0){
        return INT_MAX;
    }
    if(fhq[u].val > v){
        int res = nxt(fhq[u].ls,v);
        return (res == INT_MAX ? fhq[u].val : res);
    }else{
        return nxt(fhq[u].rs,v);
    }
}
void solve(){
    int n;cin >> n;
    for(int i = 1;i <= n;i++){
        int op,x;cin >> op >> x;
        if(op == 1){
            add(x);
        }else if(op == 2){
            remove(x);
        }else if(op == 3){
            cout<<rnk(x)<<"\n";
        }else if(op==4){
            cout<<kth(x)<<"\n";
        }else if(op==5){
            cout<<pre(head,x)<<"\n";
        }else{
            cout<<nxt(head,x)<<"\n";
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