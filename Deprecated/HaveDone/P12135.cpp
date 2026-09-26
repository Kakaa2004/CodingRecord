#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s1,s2;cin >> s1 >> s2;
    int len = s1.size();
    vector<int>a(len);
    for(int i = 0;i < len;i++){
        a[i] |= s1[i]=='.'?0:2;
        a[i] |= s2[i]=='.'?0:1;
    }
    int i = 0;
    int j = len-1;
    int ans = 0;
    while(i < len && a[i] == 0) i++;
    while(j >= 0 && a[j] == 0) j--;
    for(i++;i <= j;i++){    
        if(a[i]==0){
            if(a[i-1]==3){
                a[i] = 3;
                ans++;
            }else{
                a[i] = a[i-1];
                ans++;
            }
        }else{
            if(a[i-1]==3) continue;
            if(a[i]==3) continue;
            if(a[i-1]==a[i]) continue;
            else{
                a[i] = 3;
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}