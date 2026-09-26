#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const ll mod = 998244353;
const ll MOD = 1e9+7;
const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
void solve(){
    int cnt = 0;
    while(true){
        cout<<"Test NO."<<cnt<<": \n";
        system("data.exe > data.in");
        system("std.exe < data.in > std.out");
        system("solve.exe < data.in > solve.out");
        if(system("fc std.out solve.out > diff.log")){
            cout<<"Wrong Answer!\n";
            return;
        }
        cout<<"Accepted\n";
        cnt++;
    }
}
int main(){
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}