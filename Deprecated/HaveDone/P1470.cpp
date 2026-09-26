#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(vector<string>&a,string &str,int &cnt){
    string s;
    do{
        cin >> s;
        if(s!=".") a[cnt++] = s;
    }while(s!=".");
    while(cin >> s){
        str += s;
    }
}
void getNext(vector<int>&next,string s){
    int cnt = 0, i = 2;
    int m = s.size();
    next[0] = -1;
    next[1] = 0;
    while(i<m){
        if(s[i-1]==s[cnt]){
            next[i++] = ++cnt;
        }else if(cnt>0){
            cnt = next[cnt];
        }else{
            next[i++] = 0;
        }
    }
}
void solve(){
    vector<string>a(305);
    string str;
    int cnt = 0;
    read(a,str,cnt);
    int len1 = str.size();
    vector<int>next(300);
    vector<int>v[len1+1];
    for(int i = 0;i < cnt;i++){
        getNext(next,a[i]);
        int x = 0,y = 0;
        int len2 = a[i].size();
        while(x<len1){
            if(str[x]==a[i][y]){
                x++;
                y++;
                if(y==len2){
                    v[x].push_back(len2);
                    y = 0;
                    x = x-len2+1;
                }
            }else if(y==0){
                x++;
            }else{
                y = next[y];
            }
        }
    }
    vector<bool>dp(len1+1);
    dp[0] = true;
    int ans = 0;
    for(int i = 1;i <= len1;i++){
        int len = v[i].size();
        if(len!=0){
            for(auto it:v[i]){
                if(dp[i-it]){
                    dp[i] = true;
                    ans = min(i,ans);
                    break;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--){
        solve();
    }
    return 0;
}