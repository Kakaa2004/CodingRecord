#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>a(105);
ll rec[70][10][2];
int n;
ll dfs(int cnt,int last,int en,bool zero,bool limit){
    if(cnt>=n){
        return en>=1;
    }
    if(!limit&&zero&&rec[cnt][last][en]!=-1){
        return rec[cnt][last][en];
    }
    ll ans = 0;
    if(!zero){
        ans += dfs(cnt+1,last,en,false,false);
    }
    if(!limit){
        for(int i = 1-zero;i <= 9;i++){
            ans += dfs(cnt+1,i,en || (last==4 && i == 9),true,limit&& (i==9));
        }
    }else{
        for(int i = 1-zero;i <= a[cnt];i++){
            ans += dfs(cnt+1,i, en || (last==4 && i == 9),true,limit&& (i==a[cnt]));
        }
    }
    if(!limit&&zero){
        rec[cnt][last][en] = ans;
    }
    return ans;
}
void solve(){
    memset(rec,-1,sizeof(rec));
    string s;cin >> s;
    n = s.size();
    for(int i = 0;i < n;i++){
        a[i] = s[i]-'0';
    }
    cout<<dfs(0,0,0,false,true)<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}