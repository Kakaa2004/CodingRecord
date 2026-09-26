#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1000 + 5;
const int M = 1000 + 5;
int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {-2,-1,1,2,2,1,-1,-2};
struct node{
    int x;
    int y;
    int cnt;
    int fa;
};

vector<vector<int>>rec;
vector<string>ans;
void printRoad(int x,int y,int fa){
    while(fa!=-1){
        ans.push_back(to_string(x)+" "+to_string(y)+"\n");
        x -= dx[fa];
        y -= dy[fa];
        fa = rec[x][y];
    }
    for(int i = ans.size() -1; i >= 0;i--){
        cout<<ans[i];
    }
    return ;
}
void solve(){
    int n,m,k;cin >> n >> m >> k;
    int x1,y1,x2,y2;cin >> x1 >> y1 >> x2 >> y2;
    rec.resize(n+1,vector<int>(m+1));
    vector<vector<bool>>vis(n+1,vector<bool>(m+1));


    queue<node>q;
    q.push({x1,y1,0,-1});
    while(q.size()){
        auto p = q.front(); q.pop();
        rec[p.x][p.y] = p.fa;
        if(p.x == x2 && p.y == y2){
            if(p.cnt > k || (p.cnt < k && (k - p.cnt)%2 == 1)){
                cout<<"No\n";
            }else if(p.cnt == k){
                cout<<"Yes\n";
                printRoad(p.x,p.y,p.fa);
            }else if((k - p.cnt)%2 == 0){
                cout<<"Yes\n";
                int tx = p.x - dx[p.fa];
                int ty = p.y - dy[p.fa];
                int fa = rec[tx][ty];
                printRoad(tx,ty,fa);
                cout<<p.x <<" "<<p.y <<"\n";
                for(int i = 0;2*i < (k - p.cnt);i++){
                    cout<<tx<<" "<<ty<<"\n";
                    cout<<p.x <<" "<<p.y <<"\n";
                }
            }
            return ;
        }
        if(p.cnt > k){
            cout<<"No\n";
            return ;
        }
        vis[p.x][p.y] = true;
        for(int i = 0;i < 8;i++){
            int xx = p.x + dx[i];
            int yy = p.y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy]) continue;
            q.push({xx,yy,p.cnt+1,i});
        }
    }
    cout<<"No\n";

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t = 1; // cin >> t;
    while(t--) solve();
    
    return 0;
}