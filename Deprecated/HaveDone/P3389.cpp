#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
const double eps = 1e-7;
int n;
double a[N][N];
void Swap(int x,int y){
    for(int i = 1;i <= n+1;i++){
        swap(a[x][i],a[y][i]);
    }
}
void gauss(){ //高斯消元
    for(int i = 1;i <= n;i++){
        int Max = i;
        for(int j = 1;j <= n;j++){
            if(j < i && a[j][j] >= eps){
                continue;
            }
            if(abs(a[j][i]) > abs(a[Max][i])){
                Max = j;
            }
        }
        Swap(i,Max);
        if(abs(a[i][i]) >= eps){
            for(int j = n+1;j >= i;j--){
                a[i][j] /= a[i][i];
            }
            for(int j = 1;j <= n;j++){
                if(i!=j){
                    for(int k = n+1;k >= i;k--){
                        a[j][k] -= a[j][i]*a[i][k];
                    }
                }
            }
        }
    }
}
void solve(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n+1;j++){
            cin >> a[i][j];
        }
    }
    gauss();
    for(int i = 1;i <= n;i++){
        if(a[i][i]<eps){
            printf("No Solution\n");
            return ;
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%.2lf\n",a[i][n+1]);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}