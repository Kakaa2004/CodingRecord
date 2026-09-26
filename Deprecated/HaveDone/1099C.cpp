#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
    string s;cin >> s;
    int k; cin >> k;
    int len = s.size();
    int c1 = 0,c2 = 0;
    for(char ch:s){
        if(ch=='?') c1++;
        if(ch=='*') c2++;
    }
    int pure = len - (2*c1+2*c2);
    if(k < pure){
        cout<<"Impossible\n";
        return ;
    }
    if(k-pure <= c1+c2){
        int cnt = k-pure;
        for(int i = 0;i < len;i++){
            if(s[i]=='*'||s[i]=='?') continue;
            if(i==len-1){
                cout<<s[i];
            }else{
                if(s[i+1]=='?'||s[i+1]=='*'){
                    if(cnt){
                        cout<<s[i];
                        cnt--;
                    }
                }else{
                    cout<<s[i];
                }
            }
        }
        cout<<"\n";
    }else{
        if(c2==0){
            cout<<"Impossible\n";
            return ;
        }
        int cnt = k-pure-c1-c2;
        for(int i = 0;i < len;i++){
            if(s[i]=='*'||s[i]=='?') continue;
            if(i==len-1) cout<<s[i];
            else if(s[i+1]=='*'){
                if(cnt){
                    for(int d = 0;d <= cnt;d++) cout<<s[i];
                    cnt = 0;
                }else cout<<s[i];
            }else cout<<s[i];
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    return 0;
}