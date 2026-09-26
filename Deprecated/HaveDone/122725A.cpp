#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string str[] = {"Kato_Shoko","Kato_Shoko","koishiYun",
                "Kato_Shoko","Kato_Shoko","koishiYun"};
void solve(){
    int a;cin >> a;
    cout<<str[a-1]<<"\n";
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1;  cin >> t;
    while(t--) solve();
    
    return 0;
}