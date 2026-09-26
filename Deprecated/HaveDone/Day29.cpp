/*
    ST表做法
    静态区间最值
*/

#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int N = 5e5+5;
int a[N];
int dp_min[N][20],dp_max[N][20];
int n,q;
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
void build(){
    for(int i = 1;i <= n;i++){
        dp_min[i][0] = a[i];
        dp_max[i][0] = a[i];
    }
    int k = log2(n);
    for(int i = 1;i <= k;i++){
        for(int j = 1;j + (1<<i) <= n+1;j++){
            dp_min[j][i] = min(dp_min[j][i-1],dp_min[j+(1<<(i-1))][i-1]);
            dp_max[j][i] = min(dp_max[j][i-1],dp_max[j+(1<<(i-1))][i-1]); 
        }
    }
}
int query1(int l,int r){
    int k = log2(r-l+1);
    return  min(dp_min[l][k],dp_min[r-(1<<k)+1][k]);
}
int query2(int l,int r){
    int k = log2(r-l+1);
    return min(dp_max[l][k],dp_max[r-(1<<k)+1][k]);
}
void solve(){
    n = read();q = read();
    for(int i = 1;i <= n;i++){
        a[i] = read();
    }
    build();
    for(int i = 1;i <= q;i++){
        int op = read(),l = read(),r = read();
        if(op==1){
            printf("%d\n",query1(l,r));
        }else{
            printf("%d\n",query2(l,r));
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