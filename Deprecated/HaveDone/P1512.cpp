#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2010][13][32];
int getMaxDay(int y,int m){
    int ans = 0;
    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            ans =  31;
            break;
        case 2:
            ans =  28 + ((y%4==0 && y%100!=0) || (y%400)==0);
            break;
        default:
            ans =  30;
    }
    return ans;
}
bool addM(int& y,int& m,int& d){
    if(m==12){
        y++;
        m = 1; 
        if(y > 2006 || (y==2006 && m > 11) || (y==2006 && m == 11 && d > 4)){
        return false;
    }
        return true;
    }
    int tmp = getMaxDay(y,m+1);
    if(tmp<d){
        return false;
    }else{
        m++;
        if(y > 2006 || (y==2006 && m > 11) || (y==2006 && m == 11 && d > 4)){
            return false;
        }
        return true;
    }
}
bool addD(int& y,int& m,int& d){
    int tmp = getMaxDay(y,m);
    if(tmp==d){
        d = 1;
        addM(y,m,d);
    }else{
        d++;
    }
    if(y > 2006 || (y==2006 && m > 11) || (y==2006 && m == 11 && d > 4)){
        return false;
    }
    return true;
}
bool dfs(int y,int m,int d){
    if(dp[y][m][d]!=-1) return dp[y][m][d];
    if(y==2006&&m==11&&d==4) return false;
    int ty = y,tm = m,td = d;
    int ky = y,km = m,kd = d;
    bool ans = false;
    if(addD(ty,tm,td)){
        ans = ans || (!dfs(ty,tm,td));
    }
    if(addM(ky,km,kd)){
        ans = ans || !dfs(ky,km,kd);
    }
    return dp[y][m][d] = ans;
}
void solve(){
    int y,m,d;
    cin >> y >> m >> d;
    cout<<(dfs(y,m,d)?"YES\n":"NO\n");
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    memset(dp,-1,sizeof(dp));
    int t = 1; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}