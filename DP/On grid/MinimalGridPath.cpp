//Tóm tắt đề bài
//Bạn được cho một lưới vuông n × n.
//Mỗi ô trong lưới chứa một chữ cái in hoa (A–Z).
//Bạn bắt đầu ở ô trên-trái (1,1) và cần đi đến ô dưới-phải (n,n).
//Mỗi bước bạn chỉ được:
//đi sang phải
//hoặc đi xuống dưới
//Khi đi qua các ô, bạn ghép các chữ cái lại thành một chuỗi.

//Mục tiêu
//Tìm chuỗi nhỏ nhất theo thứ tự từ điển (lexicographically minimal) có thể tạo ra từ một đường đi hợp lệ.
//Sol: DP theo lớp BFS
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
#define se second
#define fi first
#define pb push_back
using namespace std;
const ll INF = 1e18 + 9;
const ll MOD = 1e9+7;
const int maxn = 3009;
int n;
ll dp[maxn][maxn];
char a[maxn][maxn];
bool visited[maxn][maxn];
void solve(){
    cin >> n;
    FOR(i,1,n) FOR(j,1,n) cin >> a[i][j];
 
    vector<pair<int,int>> cur,nxt;
    vector<char> ans;
    cur.pb({1,1});
    ans.pb(a[1][1]);
    visited[1][1] = 1;
        FOR(i,0,2*n-3){
        char best = '{';
        for(auto [x,y]: cur){
            if(x <= n-1) best = min(best,a[x+1][y]);
            if(y <= n-1) best = min(best,a[x][y+1]);
        }
        nxt.clear();
        ans.pb(best);
        for(auto [x,y]: cur){
            if(a[x+1][y] == best && !visited[x+1][y]){
                    nxt.pb({x+1,y}); visited[x+1][y] = 1;
            }
            if(a[x][y+1] == best && !visited[x][y+1]){
                    nxt.pb({x,y+1}); visited[x][y+1] = 1;
            }
        }
        cur.swap(nxt);
        }
   for(auto x: ans) cout << x;
 }
int main(){
//    freopen("nocross.in","r",stdin);
//    freopen("nocross.out","w",stdout);
    solve();
