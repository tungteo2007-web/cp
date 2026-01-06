//Bài toán COWRUN – Tóm tắt
//Có N con bò (1 ≤ N ≤ 1000) đang đứng ngoài hàng rào tại các vị trí khác nhau trên một trục số.
//Vị trí của bò thứ i là P_i (−500000 ≤ P_i ≤ 500000, P_i ≠ 0).
//Nông dân John (FJ) bắt đầu tại vị trí 0.
//FJ di chuyển với tốc độ 1 đơn vị khoảng cách / phút.
//Khi FJ chạm tới vị trí của bò, anh ta lập tức trói bò (không tốn thời gian).
//Mỗi phút trôi qua, mỗi con bò chưa được trói gây ra 1 đô la thiệt hại.
//Tính lượng thiệt hại nhỏ nhất có thể
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i = a, _b = (b); i<= _b; i++)
#define ll long long
#define se second
#define fi first
#define pb push_back
using namespace std;
const ll INF = 1e18 + 9;
const ll MOD = 1e9+7;
const int maxn = 1009;
int n;
ll dp[maxn][maxn][2]; // dp[i][j][1] nếu xét đến con bò thứ i bên phải và con bò thứ j bên trái và hiện tại đang ở con bò bên phải thì tốn bao nhiêu 
int c1,c2;
vector<int> pos,neg;
void solve(){
    cin >> n;
    pos.pb(0);
    neg.pb(0);
    FOR(i,1,n){
        int x; cin >> x;
        if(x < 0) neg.pb(x*-1);
        else pos.pb(x);
    }
    int n1 = pos.size() - 1;
    int n2 = neg.size() - 1;
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    FOR(i,0,n1) FOR(j,0,n2) dp[i][j][0] = dp[i][j][1] = INF;
    dp[0][0][1] = dp[0][0][0] = 0;

    FOR(i,0,n1) FOR(j,0,n2){
        if(i >= 1){
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][1] + (pos[i] - pos[i-1])*(n - i - j + 1));
        dp[i][j][1] = min(dp[i][j][1], dp[i-1][j][0] + (neg[j] + pos[i])  *(n - i - j + 1));
        }
        if(j >= 1){
            dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][0] + (neg[j] - neg[j-1])*(n-i-j+1));
            dp[i][j][0] = min(dp[i][j][0], dp[i][j-1][1] + (pos[i] + neg[j])*(n-i-j+1));
        }
    }
    cout << min(dp[n1][n2][1], dp[n1][n2][0]);
 }
int main(){
    freopen("cowrun.in","r",stdin);
    freopen("cowrun.out","w",stdout);
    solve();
}

