#include <bits/stdc++.h>
using namespace std;
string str[4];
int ans[4][4],vis[4][4];
int dx[] = {1,0,0,-1,-1,1,-1,1};
int dy[] = {0,1,-1,0,-1,-1,1,1};
int cal(int x,int y){
    int A = 0;
    for(int i = 0;i < 8;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || xx > 3 || yy < 0 || yy > 3) continue;
        A += vis[xx][yy];
    }
    return A;
}
bool check(){
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(isdigit(str[i][j])){
                int tmp = str[i][j]-'0';
                if(tmp != cal(i,j)){
                    return false;
                }
            }
        }
    }
    return true;
}
void dfs(int x,int y){
    if(y>3){
        dfs(x+1,0);
        return ;
    }
    if(x>3){
        if(check()){
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    if(vis[i][j]){
                        ans[i][j] |= 1;
                    }else{
                        ans[i][j] |= 2;
                    }
                }
            }
        }
        return ;
    }
    if(str[x][y]!='.'){
        vis[x][y] = 0;
        dfs(x,y+1);
        return;
    }
    vis[x][y] = 0;
    dfs(x,y+1);
    vis[x][y] = 1;
    dfs(x,y+1);
}
void solve(){
    for(int i = 0;i < 4;i++){
        cin >> str[i];
    }
    dfs(0,0);
    for(int i = 0;i < 4;i++){
        for(int j = 0;j < 4;j++){
            if(str[i][j]!='.'){
                cout<<str[i][j];
            }
            else if(ans[i][j]==1){
                cout<<"X";
            }else if(ans[i][j]==2){
                cout<<"O";
            }else{
                cout<<".";
            }
        }
        cout<<"\n";
    }
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