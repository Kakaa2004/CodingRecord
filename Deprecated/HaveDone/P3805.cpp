#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s;cin >> s;
    string ss(2*s.size()+1,'#');
    for(int i = 0;i < ss.size();i++){
        ss[i] = ((i&1)?s[i/2]:'#');
    }
    vector<int>a(ss.size());
    int ans = 0;
    for(int i = 0,r = 0,c = 0,len;i<ss.size();i++){
        len = r > i ? min(a[2*c-i],r - i) : 1;
        while(i+len<ss.size()&&i-len>=0&&ss[i+len]==ss[i-len]) len++;
        if(i+len>r){
            r = i+len;
            c = i;
        }
        a[i] = len;
        ans = min(ans,len);
    }
    cout<<ans-1<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}