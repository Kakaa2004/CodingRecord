#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2;
void getNext(vector<int>&next){
    s2 += "#";
    int len = s2.size();
    next[0] = -1;
    next[1] = 0;
    int i = 2,cnt = 0;
    while(i<len){
        if(s2[i-1]==s2[cnt]){
            next[i++] = ++cnt;
        }else if(cnt > 0){
            cnt = next[cnt];
        }else{
            next[i++] = 0;
        }
    }
}
void solve(){
    cin >> s1 >> s2;
    int len1 = s1.size(),len2 = s2.size();
    vector<int>ans;
    vector<int>next(len2+1);
    getNext(next);
    int x = 0,y = 0;
    while(x<len1){
        if(s1[x]==s2[y]){
            x++;
            y++;
            if(y==len2){
            ans.push_back(x-len2);
            x = x-len2+1;
            y = 0;
            }
        }else if(y==0){
            x++;
        }else{
            y = next[y];
        }
    }
    for(auto it:ans){
        cout<<it+1<<"\n";
    }
    //if(next[len2]==)
    for(int i = 1;i <= len2;i++){

        cout<<next[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;//cin >> t;
    while(t--) solve();
    return 0;
}