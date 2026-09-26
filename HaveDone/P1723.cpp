#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 21000000;
char str[N],s[N];
int p[N];
void solve(){
    cin >> str;
    int n = strlen(str)*2+1;
    for(int i = 0;i < n;i++){
        s[i] = (i&1)?str[i/2]:'#';
    }
    int ans = 0;
    for(int i = 0,c = 0,r = 0,len;i<n;i++){
        len = r>i?min(p[2*c-i],r-i):1;
        while(i+len<n&&i-len>=0&&s[i+len]==s[i-len]) len++;
        if(i+len>r){
            r = i+len;
            c = i;
        }
        p[i] = len;
        ans = min(ans,len);
    }
    cout<<ans-1<<"\n";
}
int main(){
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;cin >> t;
    while(t--) solve();
    return 0;
}