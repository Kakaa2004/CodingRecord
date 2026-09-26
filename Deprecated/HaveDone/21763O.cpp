#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int col[4];
int shape[4][2050];
int n;
bool first = true;
void print(){
    if(!first){
        for(int i = 1;i <= 6*n+7;i++){
            cout<<"-";
        }
        cout<<"\n";
    }else first = false;
    for(int i = 1;i <= 6*n+7;i++){
        cout<<".";
    }
    cout<<"\n";
    auto p = [&](int a)->void{
        if(!a){
            for(int i = 1;i <= 2*n+1;i++){
                if(i==n+1) cout<<"|";
                else cout<<".";
            }
        }else{
            for(int i = 1;i <= 2*n+1;i++){
                if(abs(i-n-1)<=a) cout<<"*";
                else cout<<".";
            }
        }
        
    };
    for(int i = n+1;i >= 1;i--){
        for(int j = 1;j <= 3;j++){
            cout<<".";
            p((col[j]>=i?shape[j][i]:0));
        }
        cout<<".\n";
    }
}
void f(int x,int a,int b,int c){
    if(x==1){
        shape[b][++col[b]] = shape[a][col[a]--];
        print();
        return ;
    }
    f(x-1,a,c,b);
    shape[b][++col[b]] = shape[a][col[a]--];
    print();
    f(x-1,c,b,a);
}
void solve(){
    cin >> n;
    col[1] = n;
    for(int i = 1;i <= n;i++) shape[1][i] = n-i+1;
    print();
    if(n&1) f(n,1,2,3);
    else f(n,1,3,2);
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;// cin >> t;
    while(t--) solve();
    return 0;
}